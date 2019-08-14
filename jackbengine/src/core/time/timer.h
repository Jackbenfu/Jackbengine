//
// timer.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_H__
#define __TIMER_H__

#include "common/common.h"

namespace Jackbengine {

class Timer
{
public:
    explicit Timer(unsigned int fps);
    ~Timer();

    void start();
    void snapshot();

    float elapsedMilliseconds() const;
    float effectiveElapsedMilliseconds() const;

    unsigned int fps() const;

    bool isFixedFps() const;
    unsigned int fixedFps() const;
    void enableFixedFps(unsigned int fps);
    void disableFixedFps();

    unsigned int totalFrames() const;

private:
    void delay(unsigned int ms) const;
    unsigned int ticks() const;

    float m_start {0};
    float m_elapsedMilliseconds {0};
    float m_effectiveElapsedMilliseconds {0};

    float m_fpsElapsedMilliseconds {0};
    unsigned int m_fpsTemp {0};
    unsigned int m_fps {0};

    unsigned int m_fixedFps {0};
    float m_fixedFpsDelayTime {0};

    unsigned int m_totalFrames {0};
};

}

#endif // __TIMER_H__
