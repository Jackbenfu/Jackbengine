//
// traceInstantEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 11/06/2020.
//

#include <thread>

#include "traceInstantEvent.h"
#include "tracer.h"

namespace Jackbengine {

TraceInstantEvent::TraceInstantEvent(const char* name)
    : m_name {name}
{
    using clock = std::chrono::high_resolution_clock;

    const auto timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(clock::now()).time_since_epoch().count();
    const auto threadId = std::hash<std::thread::id> {}(std::this_thread::get_id());

    details::Tracer::instance().instant(m_name, timestamp, threadId);
}

}
