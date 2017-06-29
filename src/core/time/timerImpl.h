//
// timerImpl.h
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_IMPL_H__
#define __TIMER_IMPL_H__

#include "common.h"
#include "timer.h"

NS_BEGIN_JKB

class TimerImpl : public Timer
{
    friend class Timer;

public:
    ~TimerImpl();

private:
    TimerImpl();

    void delay(uint ms) override;
    uint getTicks() const override;
};

NS_END_JKB

#endif // __TIMER_IMPL_H__
