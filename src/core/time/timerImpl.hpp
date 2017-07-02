//
// timerImpl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_IMPL_H__
#define __TIMER_IMPL_H__

#include "common.hpp"
#include "timer.hpp"

namespace Jackbengine {

class TimerImpl : public Timer
{
    friend class Timer;

public:
    ~TimerImpl() override;

private:
    TimerImpl();

    void delay(uint ms) override;
    uint getTicks() const override;
};

} // namespace Jackbengine

#endif // __TIMER_IMPL_H__
