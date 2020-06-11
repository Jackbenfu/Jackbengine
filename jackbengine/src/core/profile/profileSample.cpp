//
// profileSample.cpp
// jackbengine
//
// Created by Damien Bendejacq on 08/06/2020.
//

#include <numeric>
#include "profileSample.h"

namespace Jackbengine::details {

ProfileSample::ProfileSample(const char* name, int size)
    : m_samples(size, 0.0f),
      m_name {name},
      m_min {0.0f},
      m_max {0.0f},
      m_average {0.0f},
      m_count {0}
{
}

const char* ProfileSample::name() const
{
    return m_name;
}

void ProfileSample::add(unsigned int totalFrames, float time)
{
    ++m_count;
    m_samples[totalFrames % m_samples.capacity()] = time;

    if (0 == totalFrames % m_samples.capacity())
    {
        m_average = std::accumulate(m_samples.begin(), m_samples.end(), 0.0f) / m_samples.capacity();
        m_min = *std::min_element(m_samples.begin(), m_samples.end());
        m_max = *std::max_element(m_samples.begin(), m_samples.end());
    }
}

float ProfileSample::min() const
{
    return m_min;
}

float ProfileSample::max() const
{
    return m_max;
}

float ProfileSample::average() const
{
    return m_average;
}

}
