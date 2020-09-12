//
// profiler.cpp
// jackbengine
//
// Created by Damien Bendejacq on 08/06/2020.
//

#include "profiler.h"

namespace Jackbengine::details {

const Timer* Profiler::s_timer;
static Profiler s_profiler;

Profiler& Profiler::instance()
{
    return s_profiler;
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
