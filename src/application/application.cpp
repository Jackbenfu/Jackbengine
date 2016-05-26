//
//  application.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 10/08/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "application.h"
#include "platform.h"

Application::Application()
{
    m_cursor = Cursor::create();
    m_input = Input::create();
    m_renderer = Renderer::create();
    m_timer = Timer::create();
    m_window = Window::create();
}

Application::~Application()
{
    for (auto pair : m_scenes)
    {
        DELETE_SAFE(pair.second);
    }
    m_scenes.clear();

    m_currentScene = nullptr;

    DELETE_SAFE(m_window);
    DELETE_SAFE(m_timer);
    DELETE_SAFE(m_renderer);
    DELETE_SAFE(m_input);
    DELETE_SAFE(m_cursor);

    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

int Application::run()
{
    if (init())
    {
        while (running())
        {
            loop();
        }
    }

    return 0;
}

bool Application::init()
{
    if (configure(m_config))
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            printf("%s\n", SDL_GetError());
            return false;
        }

        if (TTF_Init() < 0)
        {
            printf("%s\n", TTF_GetError());
            return false;
        }

        if (!Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
        {
            printf("%s\n", Mix_GetError());
            return false;
        }

        if (-1 == Mix_OpenAudio(
            MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
        {
            printf("%s\n", Mix_GetError());
            return false;
        }

        m_timer->enableFixedFps(m_config.core_fps);

        if (!m_input->init())
        {
            return false;
        }

        if (!m_window->init(
            m_config.general_title.c_str(),
            m_config.render_width,
            m_config.render_height,
            m_config.render_fullscreen))
        {
            return false;
        }

        if (!m_renderer->init(m_window))
        {
            return false;
        }

        Scene::s_cursor = m_cursor;
        Scene::s_input = m_input;
        Scene::s_renderer = m_renderer;
        Scene::s_timer = m_timer;
        Scene::s_window = m_window;

        if (!m_currentScene)
        {
            return false;
        }

        m_currentScene->init();

        return true;
    }

    return false;
}

bool Application::running() const
{
    return m_currentScene->running();
}

void Application::loop()
{
    m_currentScene->loop();

    if (m_currentScene->s_nextScene)
    {
        if (0 == strcmp(m_currentScene->name(), m_currentScene->s_nextScene))
        {
            m_currentScene->s_nextScene = nullptr;
        }
        else
        {
            map<uint, Scene*>::const_iterator it = m_scenes.begin();
            while (m_scenes.end() != it)
            {
                if (0 == strcmp(it->second->name(), m_currentScene->s_nextScene))
                {
                    m_currentScene->reset();
                    m_currentScene = it->second;
                    m_currentScene->init();

                    break;
                }

                ++it;
            }

            m_currentScene->s_nextScene = nullptr;
        }
    }
}

Scene* Application::getScene(const char *name)
{
    map<uint, Scene*>::const_iterator it = m_scenes.begin();
    while (m_scenes.end() != it)
    {
        if (0 == strcmp(it->second->name(), name))
        {
            return it->second;
        }

        ++it;
    }

    return nullptr;
}
