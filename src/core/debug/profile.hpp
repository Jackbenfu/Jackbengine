//
// profile.hpp
// jackbengine
//
// Created by Damien Bendejacq on 02/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <chrono>
#include "core/log/log.hpp"

namespace Jackbengine {

template<typename Precision>
class Profile
{
    using clock = std::chrono::high_resolution_clock;

public:
    explicit Profile(const char *name, bool core)
        : m_name {name},
          m_start {clock::now()},
          m_core {core}
    {
    }

    ~Profile()
    {
        __attribute__((unused)) const auto format = "{} ({} {})";
        __attribute__((unused)) auto duration = clock::now() - m_start;

        if (m_core)
        {
            LOG_CORE_TRACE(
                format,
                m_name,
                std::chrono::duration_cast<Precision>(duration).count(),
                unit()
            );
        }
        else
        {
            LOG_TRACE(
                format,
                m_name,
                std::chrono::duration_cast<Precision>(duration).count(),
                unit()
            );
        }
    }

private:
    inline const char *unit();

    const char *m_name;
    clock::time_point m_start;
    bool m_core;
};

template<>
inline const char *Profile<std::chrono::seconds>::unit()
{
    return "seconds";
}

template<>
inline const char *Profile<std::chrono::milliseconds>::unit()
{
    return "milliseconds";
}

template<>
inline const char *Profile<std::chrono::microseconds>::unit()
{
    return "microseconds";
}

template<>
inline const char *Profile<std::chrono::nanoseconds>::unit()
{
    return "nanoseconds";
}

#define PROFILE_CORE_SECONDS(name)       ::Jackbengine::Profile<std::chrono::seconds> __profile__(name, true)
#define PROFILE_CORE_MILLISECONDS(name)  ::Jackbengine::Profile<std::chrono::milliseconds> __profile__(name, true)
#define PROFILE_CORE_MICROSECONDS(name)  ::Jackbengine::Profile<std::chrono::microseconds> __profile__(name, true)
#define PROFILE_CORE_NANOSECONDS(name)   ::Jackbengine::Profile<std::chrono::nanoseconds> __profile__(name, true)
#define PROFILE_SECONDS(name)            ::Jackbengine::Profile<std::chrono::seconds> __profile__(name, false)
#define PROFILE_MILLISECONDS(name)       ::Jackbengine::Profile<std::chrono::milliseconds> __profile__(name, false)
#define PROFILE_MICROSECONDS(name)       ::Jackbengine::Profile<std::chrono::microseconds> __profile__(name, false)
#define PROFILE_NANOSECONDS(name)        ::Jackbengine::Profile<std::chrono::nanoseconds> __profile__(name, false)

}

#endif // __PROFILE_H__
