//
// application.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "pch.h"
#include "application.h"

namespace Jackbengine {

Application::Application(ApplicationConfig &config)
{
    Log::init();
    srand(time(nullptr)); // NOLINT

    {
        PROFILE("Application::Application")

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

        m_timer = std::make_unique<Timer>(config.core_fps);
        m_cursor = std::make_unique<Cursor>();
        m_input = std::make_unique<Input>();
        m_window = std::make_unique<Window>(config.general_title, config.render_width, config.render_height, config.render_fullscreen);
        m_renderer = std::make_unique<Renderer>(*m_window);
        m_eventManager = std::make_unique<details::EventManager>(BIND_EVENT_CALLBACK(onEvent));
    }
}

Application::~Application()
{
    {
        PROFILE("Application::~Application")
        Mix_Quit();
        TTF_Quit();
        SDL_Quit();
    }
}

bool Application::running() const
{
    return m_running;
}

void Application::frame()
{
    {
//        PROFILE("Application::frame")

        m_timer->start();
        const auto delta = m_timer->elapsedSeconds();

        m_renderer->clear();
        //m_input->update();
        m_eventManager->update();

        userFrame(delta);

        m_renderer->present();
        m_timer->snapshot();
    }
}

void Application::userFrame(float delta)
{
    {
//        PROFILE("Application::userFrame")
        frame(delta);
    }
}

void Application::onEvent(Event &e)
{
    EventDispatcher dispatcher(e);

    dispatcher.dispatch<ApplicationCloseEvent>(BIND_EVENT_CALLBACK(onApplicationCloseEvent));
    dispatcher.dispatch<KeyDownEvent>(BIND_EVENT_CALLBACK(onKeyDownEvent));
    dispatcher.dispatch<KeyUpEvent>(BIND_EVENT_CALLBACK(onKeyUpEvent));
    dispatcher.dispatch<KeyPressEvent>(BIND_EVENT_CALLBACK(onKeyPressEvent));
    dispatcher.dispatch<MouseMotionEvent>(BIND_EVENT_CALLBACK(onMouseMotionEvent));
    dispatcher.dispatch<MouseDownEvent>(BIND_EVENT_CALLBACK(onMouseDownEvent));
    dispatcher.dispatch<MouseUpEvent>(BIND_EVENT_CALLBACK(onMouseUpEvent));
    dispatcher.dispatch<MouseClickEvent>(BIND_EVENT_CALLBACK(onMouseClickEvent));
}

bool Application::onApplicationCloseEvent(const ApplicationCloseEvent &)
{
    m_running = false;
    return true;
}

bool Application::onKeyDownEvent(const KeyDownEvent &) // NOLINT
{
    return true;
}

bool Application::onKeyUpEvent(const KeyUpEvent &) // NOLINT
{
    return true;
}

bool Application::onKeyPressEvent(const KeyPressEvent &) // NOLINT
{
    return true;
}

bool Application::onMouseMotionEvent(const MouseMotionEvent &) // NOLINT
{
    return true;
}

bool Application::onMouseDownEvent(const MouseDownEvent &) // NOLINT
{
    return true;
}

bool Application::onMouseUpEvent(const MouseUpEvent &) // NOLINT
{
    return true;
}

bool Application::onMouseClickEvent(const MouseClickEvent &) // NOLINT
{
    return true;
}

}