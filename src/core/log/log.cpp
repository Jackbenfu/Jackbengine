//
// log.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#include "log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Jackbengine {

std::shared_ptr<spdlog::logger> Log::s_coreLogger;
std::shared_ptr<spdlog::logger> Log::s_appLogger;

void Log::init()
{
    spdlog::set_pattern("%^[%D %T] [%P] [%t] [%n] [%l] %v%$");
    s_coreLogger = spdlog::stdout_color_mt("ENGINE");
    s_coreLogger->set_level(spdlog::level::trace);

    s_appLogger = spdlog::stdout_color_mt("   APP");
    s_appLogger->set_level(spdlog::level::trace);
}

}
