//
// timer.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TIME_H__
#define __TIME_H__

#include "common.hpp"

namespace Jackbengine {

class Timer
{
public:
    virtual ~Timer();

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

    static Timer* create();

protected:
    Timer();

    virtual void delay(uint ms) = 0;
    virtual uint getTicks() const = 0;

    uint m_start = 0;
    uint m_elapsedMilliseconds = 0;
    uint m_effectiveElapsedMilliseconds = 0;

    uint m_fpsElapsedMilliseconds = 0;
    uint m_fpsTemp = 0;
    uint m_fps = 0;

    uint m_fixedFps = 0;
    uint m_fixedFpsDelayTime = 0;

    uint m_totalFrames = 0;
};

} // namespace Jackbengine

#endif // __TIME_H__
