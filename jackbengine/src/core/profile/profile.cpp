//
// profile.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
//

#include "profiler.h"

namespace Jackbengine {

Profile::Profile(const char* name)
    : m_name {name},
      m_start {clock::now()}
{
}

Profile::~Profile()
{
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(clock::now()).time_since_epoch().count();
    auto us = end - start;
    auto ms = us * .001;

    auto& profiler = details::Profiler::instance();
    auto it = std::find_if(
        profiler.m_profiles.begin(),
        profiler.m_profiles.end(),
        [this](const details::ProfileSample& ps) { return m_name == ps.name(); }
    );

    details::ProfileSample* ps;
    if (profiler.m_profiles.end() == it)
    {
        ps = &profiler.m_profiles.emplace_back(m_name, (int) details::Profiler::s_timer->targetFps());
    }
    else
    {
        ps = &(*it);
    }

    ps->add(details::Profiler::s_timer->totalFrames(), ms);
}

}
