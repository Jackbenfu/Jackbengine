//
// profiler.cpp
// jackbengine
//
// Created by Damien Bendejacq on 08/06/2020.
//

#include "profiler.h"

namespace Jackbengine::details {

const Timer* Profiler::s_timer;

Profiler& Profiler::instance()
{
    static Profiler instance;

    return instance;
}

void Profiler::init(const Timer* timer)
{
    s_timer = timer;
}

const Timer* Profiler::timer()
{
    return s_timer;
}

}
