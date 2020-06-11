//
// traceInstantEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 11/06/2020.
//

#ifndef __TRACE_INSTANT_EVENT_H__
#define __TRACE_INSTANT_EVENT_H__

namespace Jackbengine {

class TraceInstantEvent
{
public:
    explicit TraceInstantEvent(const char* name);

private:
    const char* m_name;
};

}

#ifdef __RELEASE_PROFILE__
#define TRACE_INSTANT_EVENT(name)   Jackbengine::TraceInstantEvent TOKENPASTE(trace, __LINE__)(name)
#else
#define TRACE_INSTANT_EVENT(name)   void(0)
#endif

#endif // __TRACE_INSTANT_EVENT_H__
