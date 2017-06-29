//
// timerImpl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "timerImpl.h"
#include "platform.h"

TimerImpl::TimerImpl()
{
}

TimerImpl::~TimerImpl()
{
}

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
