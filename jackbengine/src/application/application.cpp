//
// application.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "core/log/profile.h"
#include "core/sdl/sdlinc.h"
#include "core/imgui/imguiLoader.h"
#include "application.h"

namespace Jackbengine {

Application::Application(ApplicationConfig &config)
{
    Log::init();
    srand(time(nullptr));

    {
        NO_PROFILE("Application::Application")

#ifdef EMSCRIPTEN
        if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_TIMER | SDL_INIT_HAPTIC)) < 0)
#else
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
#endif
        {
            throw std::runtime_error(SDL_GetError());
        }

        if (TTF_Init() < 0)
        {
            throw std::runtime_error(TTF_GetError());
        }

        if (0 == Mix_Init((unsigned) MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
        {
            throw std::runtime_error(Mix_GetError());
        }

        if (-1 == Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
        {
            throw std::runtime_error(Mix_GetError());
        }

        m_timer = std::make_unique<details::Timer>(config.core_fps);
        m_cursor = std::make_unique<details::Cursor>();
        m_window = std::make_unique<details::Window>(
            config.general_title,
            config.render_width,
            config.render_height,
            config.render_fullscreen
        );
        m_renderer = std::make_unique<details::GlRenderer>(*m_window);
        m_eventManager = std::make_unique<details::EventManager>(BIND_EVENT_CALLBACK(&Application::onEvent));
        m_layerManager = std::make_unique<details::LayerManager>();

        details::initImGui(m_window.get());

        m_layerManager->add<DebugLayer>(m_timer.get(), m_window.get());

        m_renderer->initTextureTest();
    }
}

Application::~Application()
{
    {
        NO_PROFILE("Application::~Application")

        details::destroyImGui();

        Mix_Quit();
        TTF_Quit();
        SDL_Quit();
    }
}

bool Application::running() const
{
    return m_running;
}

void Application::update()
{
    {
        NO_PROFILE("Application::frame")

        const auto delta = m_timer->elapsedSeconds();
        m_timer->start();
        m_renderer->clear();

        m_eventManager->update(delta);
        userUpdate(delta);
        m_renderer->textureTest();
        m_layerManager->update(delta);

        m_renderer->present();
        m_timer->snapshot();
    }
}

void Application::userUpdate(float delta)
{
    {
        NO_PROFILE("Application::userFrame")
        update(delta);
    }
}

void Application::onEvent(Event &e)
{
    EventDispatcher dispatcher(e);
    dispatcher.dispatch<ApplicationCloseEvent>(BIND_EVENT_CALLBACK(&Application::onApplicationCloseEvent));

    m_layerManager->onEvent(e);
}

bool Application::onApplicationCloseEvent(const ApplicationCloseEvent &)
{
    m_running = false;
    return true;
}

}
