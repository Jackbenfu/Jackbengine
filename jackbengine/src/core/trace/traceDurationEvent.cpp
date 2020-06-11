//
// traceDurationEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 11/06/2020.
//

#include <thread>
#include <chrono>

#include "traceDurationEvent.h"

namespace Jackbengine {

TraceDurationEvent::TraceDurationEvent(const char* name)
    : m_name {name},
      m_start {clock::now()}
{
}

TraceDurationEvent::~TraceDurationEvent()
{
    const auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
    const auto end = std::chrono::time_point_cast<std::chrono::microseconds>(clock::now()).time_since_epoch().count();
    const auto threadId = std::hash<std::thread::id> {}(std::this_thread::get_id());

    details::Tracer::instance().duration(m_name, start, end, threadId);
}

}
