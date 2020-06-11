//
// profileSample.h
// jackbengine
//
// Created by Damien Bendejacq on 08/06/2020.
//

#ifndef __PROFILE_SAMPLE_H__
#define __PROFILE_SAMPLE_H__

#include <vector>

namespace Jackbengine::details {

struct ProfileSample
{
public:
    ProfileSample(const char* name, int size);

    [[nodiscard]] const char* name() const;
    [[nodiscard]] float min() const;
    [[nodiscard]] float max() const;
    [[nodiscard]] float average() const;

    void add(unsigned int totalFrames, float time);

private:
    std::vector<float> m_samples;
    const char* m_name;
    float m_min;
    float m_max;
    float m_average;
    int m_count;
};

}

#endif // __PROFILE_SAMPLE_H__
