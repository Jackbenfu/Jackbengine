//
// traceDurationEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 11/06/2020.
//

#ifndef __TRACE_DURATION_EVENT_H__
#define __TRACE_DURATION_EVENT_H__

#include <chrono>

#include "tracer.h"

namespace Jackbengine {

class TraceDurationEvent
{
    using clock = std::chrono::high_resolution_clock;

public:
    explicit TraceDurationEvent(const char* name);
    ~TraceDurationEvent();

private:
    const char* m_name;
    clock::time_point m_start;
};

}

#ifdef __RELEASE_PROFILE__
#define TRACE_DURATION_EVENT(name)  Jackbengine::TraceDurationEvent TOKENPASTE(trace, __LINE__)(name)
#else
#define TRACE_DURATION_EVENT(name)  void(0)
#endif

#endif // __TRACE_DURATION_EVENT_H__
