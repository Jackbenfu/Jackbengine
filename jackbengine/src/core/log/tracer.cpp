//
// tracer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/11/2019.
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

    m_os << R"delim({"otherData": {},"traceEvents":[)delim";
    m_os.flush();
}

Tracer::~Tracer()
{
    m_os << "]}";
    m_os.flush();

    m_os.close();
}

void Tracer::trace(const char *name, long long start, long long end, unsigned int threadId)
{
    if (m_count++ > 0)
    {
        m_os << ',';
    }

    m_os << "{";
    m_os << R"delim("cat":"function",)delim";
    m_os << R"delim("dur":)delim" << (end - start) << ',';
    m_os << R"delim("name":")delim" << name << R"delim(",)delim";
    m_os << R"delim("ph":"X",)delim";
    m_os << R"delim("pid":0,)delim";
    m_os << R"delim("tid":)delim" << threadId << ',';
    m_os << R"delim("ts":)delim" << start;
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
