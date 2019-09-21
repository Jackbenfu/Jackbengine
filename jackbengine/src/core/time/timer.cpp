//
// timer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include <vector>
#include <numeric>

#include "timer.h"
#include "core/sdl/sdlinc.h"

namespace Jackbengine::details {

Timer::Timer(unsigned int fps)
{
    m_targetFps = fps;
    m_targetFrameTime = 1000.0f / (float) fps;
    m_frameTimes = std::vector<float>(fps, 0);
}

void Timer::start()
{
    m_start = ticks();
}

void Timer::snapshot()
{
    m_spentMilliseconds = ticks() - m_start;
    auto delayTime = 0.0f;

    if (0 < m_targetFps && m_spentMilliseconds < m_targetFrameTime)
    {
        delayTime = m_targetFrameTime - m_spentMilliseconds;
        m_waitingMilliseconds = delayTime;
    }
    else
    {
        m_waitingMilliseconds = 0;
    }

    m_elapsedMilliseconds = m_spentMilliseconds + m_waitingMilliseconds;

    if (m_totalFrames > m_frameTimes.capacity())
    {
        m_fps = 1000.0f / (std::accumulate(m_frameTimes.begin(), m_frameTimes.end(), 0.0f) / m_frameTimes.capacity());
    }

    m_frameTimes[m_totalFrames % m_frameTimes.capacity()] = m_elapsedMilliseconds;

    ++m_totalFrames;

    if (0 < delayTime)
    {
        delay((unsigned int) delayTime);
    }
}

std::optional<float> Timer::fps() const
{
    return m_fps;
}

float Timer::elapsedSeconds() const
{
    return m_elapsedMilliseconds * .001f;
}

float Timer::elapsedMilliseconds() const
{
    return m_elapsedMilliseconds;
}

float Timer::spentMilliseconds() const
{
    return m_spentMilliseconds;
}

float Timer::waitingMilliseconds() const
{
    return m_waitingMilliseconds;
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

float Timer::ticks() const
{
    return (float) SDL_GetTicks();
}

}
