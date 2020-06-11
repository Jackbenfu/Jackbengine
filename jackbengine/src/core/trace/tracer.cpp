//
// tracer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/11/2019.
//

// Google Chrome's Trace Event Format documentation:
// - https://docs.google.com/document/d/1CvAClvFfyA5R-PhYUmn5OOQtYMH4h6I0nSsKchNAySU/edit

#include "tracer.h"

namespace Jackbengine::details {

Tracer& Tracer::instance()
{
    static Tracer instance;

    return instance;
}

Tracer::Tracer()
{
    m_os.open("trace.json");
    m_os << R"({"otherData": {},"traceEvents":[)";
}

Tracer::~Tracer()
{
    m_os << "]}";
    m_os.flush();
    m_os.close();
}

void Tracer::duration(const char* name, long long start, long long end, unsigned int threadId)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_count++ > 0)
    {
        m_os << ',';
    }

    m_os << "{";
    m_os << R"("cat":"function",)";
    m_os << R"("dur":)" << (end - start) << ',';
    m_os << R"("name":")" << name << R"(",)";
    m_os << R"("ph":"X",)";
    m_os << R"("pid":0,)";
    m_os << R"("tid":)" << threadId << ',';
    m_os << R"("ts":)" << start;
    m_os << "}";
}

void Tracer::instant(const char* name, long long int timestamp, unsigned int threadId)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_count++ > 0)
    {
        m_os << ',';
    }

    m_os << "{";
    m_os << R"("name":")" << name << R"(",)";
    m_os << R"("ph":"i",)";
    m_os << R"("pid":0,)";
    m_os << R"("tid":)" << threadId << ',';
    m_os << R"("ts":)" << timestamp;
    m_os << "}";
}

}
