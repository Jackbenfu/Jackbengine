//
// timer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
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
    m_elapsedMillisecondsBuffer = std::vector<float>(fps, 0);
    m_spentMillisecondsBuffer = std::vector<float>(fps, 0);
    m_waitingMillisecondsBuffer = std::vector<float>(fps, 0);
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

    m_elapsedMillisecondsBuffer[m_totalFrames % m_elapsedMillisecondsBuffer.capacity()] = m_elapsedMilliseconds;
    m_spentMillisecondsBuffer[m_totalFrames % m_spentMillisecondsBuffer.capacity()] = m_spentMilliseconds;
    m_waitingMillisecondsBuffer[m_totalFrames % m_waitingMillisecondsBuffer.capacity()] = m_waitingMilliseconds;

    if (m_totalFrames > m_elapsedMillisecondsBuffer.capacity())
    {
        const auto averageElapsed = std::accumulate(
            m_elapsedMillisecondsBuffer.begin(),
            m_elapsedMillisecondsBuffer.end(),
            0.0f
        ) / m_elapsedMillisecondsBuffer.capacity();

        m_fps = 1000.0f / averageElapsed;

        if (m_totalFrames % m_elapsedMillisecondsBuffer.capacity() == 0)
        {
            m_averageElapsedMilliseconds = averageElapsed;
            m_averageSpentMilliseconds = std::accumulate(
                m_spentMillisecondsBuffer.begin(),
                m_spentMillisecondsBuffer.end(),
                0.0f
            ) / m_spentMillisecondsBuffer.capacity();
            m_averageWaitingMilliseconds = std::accumulate(
                m_waitingMillisecondsBuffer.begin(),
                m_waitingMillisecondsBuffer.end(),
                0.0f
            ) / m_waitingMillisecondsBuffer.capacity();
        }
    }

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

float Timer::averageElapsedMilliseconds() const
{
    return m_averageElapsedMilliseconds;
}

float Timer::averageSpentMilliseconds() const
{
    return m_averageSpentMilliseconds;
}

float Timer::averageWaitingMilliseconds() const
{
    return m_averageWaitingMilliseconds;
}

unsigned int Timer::totalFrames() const
{
    return m_totalFrames;
}

void Timer::delay(unsigned int ms)
{
#ifndef EMSCRIPTEN
    SDL_Delay(ms);
#else
    (void)ms;
#endif
}

float Timer::ticks()
{
    return (float) SDL_GetTicks();
}

}
