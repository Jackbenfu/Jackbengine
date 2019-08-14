//
// profile.h
// jackbengine
//
// Created by Damien Bendejacq on 02/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __PROFILE_H__
#define __PROFILE_H__

#include "log.h"

namespace Jackbengine {

class Profile
{
    using clock = std::chrono::high_resolution_clock;

public:
    explicit Profile(const char *name)
        : m_name {name},
          m_start {clock::now()}
    {
    }

    void stop()
    {
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(clock::now()).time_since_epoch().count();
        auto us = end - start;
        auto ms = us * .001;

        Jackbengine::Log::getLogger()->trace(fmt::format("PROFILE {}: {}ms ({}μs)", m_name, ms, us));
    }

private:
    const char *m_name;
    clock::time_point m_start;
};

}

#ifdef __PROFILE__

#define PROFILE(name, scope) {                      \
    auto __profile__ = Jackbengine::Profile(name);  \
    { scope }                                       \
    __profile__.stop();                             \
    }

#else

#define PROFILE(name, scope)  { scope }

#endif

#endif // __PROFILE_H__
