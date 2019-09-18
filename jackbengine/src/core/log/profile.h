//
// profile.h
// jackbengine
//
// Created by Damien Bendejacq on 02/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <chrono>

#include "log.h"

namespace Jackbengine {

class Profile
{
    using clock = std::chrono::high_resolution_clock;

public:
    explicit Profile(const char *name);
    ~Profile();

private:
    const char *m_name;
    clock::time_point m_start;
};

}

#ifdef __RELEASE_PROFILE__

#define PROFILE(name)       Profile p(name);
#define NO_PROFILE(name)

#else

#define PROFILE(name)
#define NO_PROFILE(name)

#endif

#endif // __PROFILE_H__
