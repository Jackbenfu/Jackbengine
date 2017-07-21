//
// timer2.impl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "timer2.impl.hpp"
#include "platform.hpp"

using namespace Jackbengine;

Timer2::Impl::Impl(uint fps)
{
    enableFixedFps(fps);
}

void Timer2::Impl::start()
{
    m_start = getTicks();
}

void Timer2::Impl::snapshot()
{
    ++m_totalFrames;

    m_elapsedMilliseconds = getTicks() - m_start;
    m_effectiveElapsedMilliseconds = m_elapsedMilliseconds;
    uint delayTime = 0;

    if (0 < m_fixedFps && m_elapsedMilliseconds < m_fixedFpsDelayTime)
    {
        delayTime = m_fixedFpsDelayTime - m_elapsedMilliseconds;
        m_elapsedMilliseconds += delayTime;
    }

    if (1000 < m_fpsElapsedMilliseconds)
    {
        m_fps = m_fpsTemp;
        m_fpsElapsedMilliseconds = 0;
        m_fpsTemp = 0;
    }
    else
    {
        m_fpsElapsedMilliseconds += m_elapsedMilliseconds;
        ++m_fpsTemp;
    }

    if (0 < delayTime)
    {
        delay(delayTime);
    }
}

uint Timer2::Impl::getElapsedMilliseconds() const
{
    return m_elapsedMilliseconds;
}

uint Timer2::Impl::getEffectiveElapsedMilliseconds() const
{
    return m_effectiveElapsedMilliseconds;
}

int Timer2::Impl::getFps() const
{
    return m_fps;
}

bool Timer2::Impl::isFixedFps() const
{
    return 0 < m_fixedFps;
}

int Timer2::Impl::getFixedFps() const
{
    return m_fixedFps;
}

void Timer2::Impl::enableFixedFps(uint fps)
{
    if (0 >= fps)
    {
        fps = 60; // Defaulting to 60 fps
    }

    m_fixedFps = fps;
    m_fixedFpsDelayTime = 1000 / fps;
}

void Timer2::Impl::disableFixedFps()
{
    m_fixedFps = 0;
}

uint Timer2::Impl::getTotalFrames() const
{
    return m_totalFrames;
}

void Timer2::Impl::delay(uint ms) const
{
#ifndef EMSCRIPTEN
    SDL_Delay(ms);
#endif
}

uint Timer2::Impl::getTicks() const
{
    return SDL_GetTicks();
}
