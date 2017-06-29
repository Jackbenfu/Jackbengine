//
// timer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "timer.h"
#include "timerImpl.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::start()
{
    m_start = getTicks();
}

void Timer::snapshot()
{
    ++m_totalFrames;

    m_elapsedMilliseconds = getTicks() - m_start;
    m_effectiveElapsedMilliseconds = m_elapsedMilliseconds;
    int delayTime = 0;

    if (0 < m_fixedFps &&
        m_elapsedMilliseconds < m_fixedFpsDelayTime)
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

uint Timer::getElapsedMilliseconds() const
{
    return m_elapsedMilliseconds;
}

uint Timer::getEffectiveElapsedMilliseconds() const
{
    return m_effectiveElapsedMilliseconds;
}

int Timer::getFps() const
{
    return m_fps;
}

bool Timer::isFixedFps() const
{
    return 0 < m_fixedFps;
}

int Timer::getFixedFps() const
{
    return m_fixedFps;
}

void Timer::enableFixedFps(uint value)
{
    if (0 >= value)
    {
        value = 60; // Defaulting to 60 fps
    }

    m_fixedFps = value;
    m_fixedFpsDelayTime = 1000 / value;
}

void Timer::disableFixedFps()
{
    m_fixedFps = 0;
}

uint Timer::getTotalFrames() const
{
    return m_totalFrames;
}

Timer* Timer::create()
{
    return new TimerImpl();
}
