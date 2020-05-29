//
// profile.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
//

#include "profile.h"
#include "spdlog/spdlog.h"

namespace Jackbengine {

Profile::Profile(const char* name)
    : m_name {name},
      m_start {clock::now()}
{
}

Profile::~Profile()
{
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(clock::now()).time_since_epoch().count();
    auto us = end - start;
    auto ms = us * .001;

    LOG_INFO("PROFILE {:<30} {}ms ({}μs)", m_name, ms, us);
}

}
