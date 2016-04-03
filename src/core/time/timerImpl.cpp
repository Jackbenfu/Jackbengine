//
//  timerImpl.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "timerImpl.h"

TimerImpl::TimerImpl()
{
}

TimerImpl::~TimerImpl()
{
}

void TimerImpl::delay(uint ms)
{
    SDL_Delay(ms);
}

uint TimerImpl::getTicks() const
{
    return SDL_GetTicks();
}
