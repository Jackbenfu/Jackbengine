//
// timerImpl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "timerImpl.hpp"
#include "platform.hpp"

using namespace Jackbengine;

TimerImpl::TimerImpl() = default;

TimerImpl::~TimerImpl() = default;

void TimerImpl::delay(uint ms)
{
#ifndef EMSCRIPTEN
    SDL_Delay(ms);
#endif
}

uint TimerImpl::getTicks() const
{
    return SDL_GetTicks();
}
