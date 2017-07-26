//
// application2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "application2.hpp"

// TODO remove
#include "component/audio/audioSourceComponent2.hpp"

using namespace Jackbengine;

Application2::Application2(ApplicationConfig& config)
    : m_timer(config.core_fps),
      m_window(
        config.general_title,
        config.render_width,
        config.render_height,
        config.render_fullscreen
      ),
      m_renderer(m_window)
{
    srand(static_cast<uint>(time(nullptr)));

    // TODO remove
    m_entityManager.add();
    m_entityManager.add<AudioSourceComponent2>(1, "/Users/Jackben/Documents/git/Pong/resources/left.wav");
    m_entityManager.get<AudioSourceComponent2>(1).play();
}

Application2::~Application2() = default;

bool Application2::running() const
{
    return m_running;
}

void Application2::loop()
{
    const auto deltaMultiplier = 0.001f;

    m_timer.start();
    const auto delta = m_timer.getElapsedMilliseconds() * deltaMultiplier;

    m_renderer.clear();
    m_input.update();

    frame(delta);

    m_renderer.present();

    if (m_input.quit())
    {
        m_running = false;
    }

    m_timer.snapshot();
}
