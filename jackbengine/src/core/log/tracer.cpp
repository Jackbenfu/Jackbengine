//
// tracer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/11/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include <thread>

#include "tracer.h"

namespace Jackbengine {

Tracer &Tracer::tracer()
{
    static Tracer s_tracer;

    return s_tracer;
}

Tracer::Tracer()
{
    m_os.open("trace.json");

    m_os << "{\"otherData\": {},\"traceEvents\":[";
    m_os.flush();
}

Tracer::~Tracer()
{
    m_os << "]}";
    m_os.flush();

    m_os.close();
}

void Tracer::trace(const char *name, long long start, long long end, uint32_t threadId)
{
    if (m_count++ > 0)
    {
        m_os << ",";
    }

    m_os << "{";
    m_os << "\"cat\":\"function\",";
    m_os << "\"dur\":" << (end - start) << ',';
    m_os << "\"name\":\"" << name << "\",";
    m_os << "\"ph\":\"X\",";
    m_os << "\"pid\":0,";
    m_os << "\"tid\":" << threadId << ",";
    m_os << "\"ts\":" << start;
    m_os << "}";

    m_os.flush();
}

Trace::Trace(const char *name)
    : m_name {name},
      m_start {clock::now()}
{
}

Trace::~Trace()
{
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(clock::now()).time_since_epoch().count();
    auto threadId = std::hash<std::thread::id> {}(std::this_thread::get_id());

    Tracer::tracer().trace(m_name, start, end, threadId);
}

}
