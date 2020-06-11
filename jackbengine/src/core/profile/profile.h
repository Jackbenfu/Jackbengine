//
// profile.h
// jackbengine
//
// Created by Damien Bendejacq on 02/07/2015.
//

#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <chrono>

#include "core/common/common.h"
#include "core/log/log.h"

namespace Jackbengine {

class Profile
{
    using clock = std::chrono::high_resolution_clock;

public:
    explicit Profile(const char* name);
    ~Profile();

private:
    const char* m_name;
    clock::time_point m_start;
};

}

#ifdef __RELEASE_PROFILE__
#define PROFILE(name)       Profile TOKENPASTE(profile, __LINE__)(name)
#else
#define PROFILE(name)       void(0)
#endif

#endif // __PROFILE_H__