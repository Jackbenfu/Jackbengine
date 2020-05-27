//
// tracer.h
// jackbengine
//
// Created by Damien Bendejacq on 18/11/2019.
//

/*
 * Inspired from The Cherno's gist: https://gist.github.com/TheCherno/31f135eea6ee729ab5f26a6908eb3a5e
 */

#ifndef __TRACER_H__
#define __TRACER_H__

#include <chrono>
#include <fstream>

#include "core/common/common.h"

namespace Jackbengine {

class Tracer
{
public:
    Tracer();
    ~Tracer();

    static Tracer &tracer();

    void trace(const char *name, long long start, long long end, unsigned int threadId);

private:
    std::ofstream m_os;
    int m_count {0};
};

class Trace
{
    using clock = std::chrono::high_resolution_clock;

public:
    explicit Trace(const char *name);
    ~Trace();

private:
    const char *m_name;
    clock::time_point m_start;
};

}

#ifdef __RELEASE_PROFILE__
#define TRACE(name)     Trace TOKENPASTE(trace, __LINE__)(name)
#else
#define TRACE(name)
#endif

#define NO_TRACE(name)

#endif // __TRACER_H__
