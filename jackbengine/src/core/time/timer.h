//
// timer.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
//

#ifndef __TIMER_H__
#define __TIMER_H__

#include <vector>
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
    [[maybe_unused]] [[nodiscard]] float elapsedMilliseconds() const;
    [[maybe_unused]] [[nodiscard]] float spentMilliseconds() const;
    [[maybe_unused]] [[nodiscard]] float waitingMilliseconds() const;

    [[nodiscard]] float averageElapsedMilliseconds() const;
    [[nodiscard]] float averageSpentMilliseconds() const;
    [[nodiscard]] float averageWaitingMilliseconds() const;

    [[nodiscard]] unsigned int totalFrames() const;

private:
    static void delay(unsigned int ms);
    [[nodiscard]] static float ticks();

    unsigned int m_targetFps {0};
    unsigned int m_totalFrames {0};
    float m_targetFrameTime {0};

    std::vector<float> m_elapsedMillisecondsBuffer;
    std::vector<float> m_spentMillisecondsBuffer;
    std::vector<float> m_waitingMillisecondsBuffer;

    std::optional<float> m_fps;

    float m_start {0};
    float m_elapsedMilliseconds {0};
    float m_averageElapsedMilliseconds {0};
    float m_spentMilliseconds {0};
    float m_averageSpentMilliseconds {0};
    float m_waitingMilliseconds {0};
    float m_averageWaitingMilliseconds {0};
};

}

#endif // __TIMER_H__
