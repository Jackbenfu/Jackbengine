//
// timer.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TIMER_H__
#define __TIMER_H__

#include <optional>

namespace Jackbengine::details {

class Timer
{
public:
    explicit Timer(unsigned int fps);
    ~Timer() = default;

    void start();
    void snapshot();

    [[nodiscard]] std::optional<float> fps() const;

    [[nodiscard]] float elapsedSeconds() const;
    [[nodiscard]] float elapsedMilliseconds() const;
    [[nodiscard]] float spentMilliseconds() const;
    [[nodiscard]] float waitingMilliseconds() const;

    [[nodiscard]] unsigned int totalFrames() const;

private:
    void delay(unsigned int ms) const;
    [[nodiscard]] float ticks() const;

    unsigned int m_targetFps {0};
    float m_targetFrameTime {0};
    std::vector<float> m_frameTimes;
    unsigned int m_totalFrames {0};

    std::optional<float> m_fps;

    float m_start {0};
    float m_elapsedMilliseconds {0};
    float m_spentMilliseconds {0};
    float m_waitingMilliseconds {0};
};

}

#endif // __TIMER_H__
