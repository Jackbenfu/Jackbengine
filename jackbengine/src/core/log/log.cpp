//
// log.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
//

#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Jackbengine {

std::shared_ptr<spdlog::logger> Log::s_logger;

void Log::init()
{
    spdlog::set_pattern("%^[%D %T.%e] [%P] [%t] [%n] [%l] %v%$");
    s_logger = spdlog::stdout_color_mt("DEFAULT");
    s_logger->set_level(spdlog::level::trace);
}

}
