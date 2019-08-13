//
// profile.hpp
// jackbengine
//
// Created by Damien Bendejacq on 02/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <chrono>
#include "log.hpp"

namespace Jackbengine {

template<typename Precision>
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
        __attribute__((unused)) const auto format = "{} ({} {})";
        __attribute__((unused)) auto duration = clock::now() - m_start;

        Jackbengine::Log::getLogger()->trace(
            fmt::format(
                format, m_name, std::chrono::duration_cast<Precision>(duration).count(), unit()
            )
        );
    }

private:
    inline const char *unit();

    const char *m_name;
    clock::time_point m_start;
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

}

#ifdef DEBUG

#define PROFILE_SECONDS(name, code) {                                           \
    auto __profile__ = Jackbengine::Profile<std::chrono::seconds>(name);        \
    { code }                                                                    \
    __profile__.stop();                                                         \
    }

#define PROFILE_MILLISECONDS(name, code) {                                      \
    auto __profile__ = Jackbengine::Profile<std::chrono::milliseconds>(name);   \
    { code }                                                                    \
    __profile__.stop();                                                         \
    }

#define PROFILE_MICROSECONDS(name, code) {                                      \
    auto __profile__ = Jackbengine::Profile<std::chrono::microseconds>(name);   \
    { code }                                                                    \
    __profile__.stop();                                                         \
    }

#else

#define PROFILE_SECONDS(name, code)       { code }
#define PROFILE_MILLISECONDS(name, code)  { code }
#define PROFILE_MICROSECONDS(name, code)  { code }

#endif

#endif // __PROFILE_H__
