//
// timer.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_H__
#define __TIMER_H__

namespace Jackbengine::details {

class Timer
{
public:
    explicit Timer(unsigned int fps);
    ~Timer() = default;

    void start();
    void snapshot();

    [[nodiscard]] float elapsedSeconds() const;
    [[nodiscard]] float elapsedMilliseconds() const;
    [[nodiscard]] float spentMilliseconds() const;
    [[nodiscard]] float waitingMilliseconds() const;

    [[nodiscard]] unsigned int fps() const;

    [[nodiscard]] bool isFixedFps() const;
    [[nodiscard]] unsigned int fixedFps() const;
    void enableFixedFps(unsigned int fps);
    void disableFixedFps();

    [[nodiscard]] unsigned int totalFrames() const;

private:
    void delay(unsigned int ms) const;
    [[nodiscard]] unsigned int ticks() const;

    float m_start {0};
    float m_elapsedMilliseconds {0};
    float m_spentMilliseconds {0};
    float m_waitingMilliseconds {0};

    float m_fpsElapsedMilliseconds {0};
    unsigned int m_fpsTemp {0};
    unsigned int m_fps {0};

    unsigned int m_fixedFps {0};
    float m_fixedFpsDelayTime {0};

    unsigned int m_totalFrames {0};
};

}

#endif // __TIMER_H__
