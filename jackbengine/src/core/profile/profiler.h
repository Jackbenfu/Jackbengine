//
// profiler.h
// jackbengine
//
// Created by Damien Bendejacq on 08/06/2020.
//

#ifndef __PROFILER_H__
#define __PROFILER_H__

#include <vector>
#include "core/time/timer.h"
#include "profile.h"
#include "profileSample.h"

namespace Jackbengine::details {

class Profiler
{
    friend class Jackbengine::Profile;

public:
    Profiler() = default;
    ~Profiler() = default;

    static Profiler& instance();

    static void init(const Timer* timer);

    static const Timer* timer();

    std::vector<ProfileSample>::iterator begin()
    {
        return m_profiles.begin();
    }

    std::vector<ProfileSample>::iterator end()
    {
        return m_profiles.end();
    }

private:
    static const Timer* s_timer;

    std::vector<ProfileSample> m_profiles;
};

}

#endif // __PROFILER_H__
