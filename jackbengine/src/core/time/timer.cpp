//
// timer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "core/sdl/sdl.hpp"
#include "timer.hpp"

namespace Jackbengine {

Timer::Timer(unsigned int fps)
{
    enableFixedFps(fps);
}

Timer::~Timer() = default;

void Timer::start()
{
    m_start = ticks();
}

void Timer::snapshot()
{
    ++m_totalFrames;

    m_elapsedMilliseconds = ticks() - m_start;
    m_effectiveElapsedMilliseconds = m_elapsedMilliseconds;
    float delayTime = 0;

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
        delay((unsigned int) delayTime);
    }
}

float Timer::elapsedMilliseconds() const
{
    return m_elapsedMilliseconds;
}

float Timer::effectiveElapsedMilliseconds() const
{
    return m_effectiveElapsedMilliseconds;
}

int Timer::fps() const
{
    return m_fps;
}

bool Timer::isFixedFps() const
{
    return 0 < m_fixedFps;
}

int Timer::fixedFps() const
{
    return m_fixedFps;
}

void Timer::enableFixedFps(unsigned int fps)
{
    if (0 >= fps)
    {
        fps = 60; // Defaulting to 60 fps
    }

    m_fixedFps = fps;
    m_fixedFpsDelayTime = 1000.0f / fps;
}

void Timer::disableFixedFps()
{
    m_fixedFps = 0;
}

unsigned int Timer::totalFrames() const
{
    return m_totalFrames;
}

void Timer::delay(unsigned int ms) const
{
#ifndef EMSCRIPTEN
    SDL_Delay(ms);
#else
    (void)ms;
#endif
}

unsigned int Timer::ticks() const
{
    return SDL_GetTicks();
}

}
