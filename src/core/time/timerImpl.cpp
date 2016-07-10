//
//  timerImpl.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
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
