//
// timer2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "timer2.hpp"
#include "timer2.impl.hpp"

using namespace Jackbengine;

Timer2::Timer2(uint fps)
    : m_impl {std::make_unique<Impl>(fps)}
{
    // Nothing
}

Timer2::~Timer2() = default;

void Timer2::start()
{
    m_impl->start();
}

void Timer2::snapshot()
{
    m_impl->snapshot();
}

uint Timer2::elapsedMilliseconds() const
{
    return m_impl->elapsedMilliseconds();
}

uint Timer2::effectiveElapsedMilliseconds() const
{
    return m_impl->effectiveElapsedMilliseconds();
}

int Timer2::fps() const
{
    return m_impl->fps();
}

bool Timer2::isFixedFps() const
{
    return m_impl->isFixedFps();
}

int Timer2::fixedFps() const
{
    return m_impl->fixedFps();
}

void Timer2::enableFixedFps(uint fps)
{
    m_impl->enableFixedFps(fps);
}

void Timer2::disableFixedFps()
{
    m_impl->disableFixedFps();
}

uint Timer2::totalFrames() const
{
    return m_impl->totalFrames();
}
