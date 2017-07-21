//
// timer2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_2_H__
#define __TIMER_2_H__

#include <memory>
#include "common.hpp"

namespace Jackbengine {

class Timer2
{
    DISALLOW_COPY_AND_MOVE(Timer2)

public:
    explicit Timer2(uint fps);
    ~Timer2();

    void start();
    void snapshot();

    uint getElapsedMilliseconds() const;
    uint getEffectiveElapsedMilliseconds() const;

    int getFps() const;

    bool isFixedFps() const;
    int getFixedFps() const;
    void enableFixedFps(uint fps);
    void disableFixedFps();

    uint getTotalFrames() const;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __TIMER_2_H__
