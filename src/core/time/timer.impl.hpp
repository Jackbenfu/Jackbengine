//
// timer.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_IMPL_H__
#define __TIMER_IMPL_H__

#include "timer.hpp"

namespace Jackbengine {

class Timer::Impl
{
public:
    explicit Impl(uint fps);

    void start();
    void snapshot();

    float elapsedMilliseconds() const;
    float effectiveElapsedMilliseconds() const;

    int fps() const;

    bool isFixedFps() const;
    int fixedFps() const;
    void enableFixedFps(uint fps);
    void disableFixedFps();

    uint totalFrames() const;

private:
    void delay(uint ms) const;
    uint ticks() const;

    float m_start {0};
    float m_elapsedMilliseconds {0};
    float m_effectiveElapsedMilliseconds {0};

    float m_fpsElapsedMilliseconds {0};
    uint m_fpsTemp {0};
    uint m_fps {0};

    uint m_fixedFps {0};
    float m_fixedFpsDelayTime {0};

    uint m_totalFrames {0};
};

}

#endif // __TIMER_IMPL_H__
