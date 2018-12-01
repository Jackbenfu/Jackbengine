//
// application.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include <ctime>
#include "application.hpp"
#include "ecs/ecsManager.hpp"

namespace Jackbengine {

Application::Application(ApplicationConfig& config)
    : m_timer {std::make_unique<Timer>(config.core_fps)},
      m_cursor {std::make_unique<Cursor>()},
      m_input {std::make_unique<Input>()},
      m_window {std::make_unique<Window>(
          config.general_title, config.render_width, config.render_height, config.render_fullscreen
      )},
      m_renderer {std::make_unique<Renderer>(*m_window)}
{
    srand(static_cast<uint>(time(nullptr))); // NOLINT
}

bool Application::running() const
{
    return m_running;
}

void Application::loop()
{
    m_timer->start();

    const auto deltaMultiplier = 0.001f;
    const auto delta = m_timer->elapsedMilliseconds() * deltaMultiplier;

    m_renderer->clear();
    m_input->update();

    EcsManager::getManager().frame(delta);

    frame(delta);

    m_renderer->present();

    if (m_input->quit())
    {
        exit();
    }

    m_timer->snapshot();
}

void Application::exit()
{
    m_running = false;
}

}
