//
// application.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "application.hpp"
#include "platform.hpp"

using namespace Jackbengine;

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
#ifndef EMSCRIPTEN
    SDL_Quit();
#endif
}

bool Application::init()
{
    srand(static_cast<uint>(time(nullptr)));

    if (configure(m_config))
    {
#ifdef EMSCRIPTEN
        if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_TIMER | SDL_INIT_HAPTIC)) < 0)
#else
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
#endif
        {
            LOG_ERROR("%s", SDL_GetError())
            return false;
        }

        if (TTF_Init() < 0)
        {
            LOG_ERROR("%s", TTF_GetError())
            return false;
        }

        if (!Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
        {
            LOG_ERROR("%s", Mix_GetError())
            return false;
        }

        if (-1 == Mix_OpenAudio(
            MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
        {
            LOG_ERROR("%s", Mix_GetError())
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

    if (m_currentScene->m_nextScene)
    {
        if (0 == strcmp(m_currentScene->name(), m_currentScene->m_nextScene))
        {
            m_currentScene->m_nextScene = nullptr;
        }
        else
        {
            auto it = m_scenes.begin();
            while (m_scenes.end() != it)
            {
                if (0 == strcmp(it->second->name(), m_currentScene->m_nextScene))
                {
                    m_currentScene->clear();
                    m_currentScene = it->second;
                    m_currentScene->init();

                    break;
                }

                ++it;
            }

            m_currentScene->m_nextScene = nullptr;
        }
    }
}

Scene* Application::getScene(const char *name)
{
    auto it = m_scenes.begin();
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

void Application::setSceneFeatures(Scene &scene)
{
    scene.setCursor(m_cursor);
    scene.setInput(m_input);
    scene.setRenderer(m_renderer);
    scene.setTimer(m_timer);
    scene.setWindow(m_window);
}
