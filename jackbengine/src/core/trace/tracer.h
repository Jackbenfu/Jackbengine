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

#include <fstream>
#include <chrono>

#include "core/common/common.h"

namespace Jackbengine::details {

class Tracer
{
public:
    ~Tracer();

    static Tracer& instance();

    static void init();

    void duration(const char* name, long long start, long long end, unsigned int threadId);
    void instant(const char* name, long long timestamp, unsigned int threadId);

private:
    static std::ofstream m_os;
    std::mutex m_mutex;
    int m_count {0};
};

}

#endif // __TRACER_H__
