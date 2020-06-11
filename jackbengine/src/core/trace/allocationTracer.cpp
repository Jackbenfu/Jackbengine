//
// allocationTracer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 31/05/2020.
//

// TODO need to do some more tests as the following
//  replacements are not thread-safe. Thus tracing does not work.

/*
#ifdef __RELEASE_PROFILE__

#include <cstdlib>

#include "core/trace/tracer.h"
#include "traceInstantEvent.h"

void* operator new(size_t size)
{
    TRACE_INSTANT_EVENT("new");
    return std::malloc(size);
}

void operator delete(void* pointer) noexcept
{
    TRACE_INSTANT_EVENT("delete");
    std::free(pointer);
}

#endif
*/
