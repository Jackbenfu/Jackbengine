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

void Log::init(LogLevel level)
{
    spdlog::set_pattern("%^[%D %T.%e] [%P] [%t] [%n] [%l] %v%$");
    s_logger = spdlog::stdout_color_mt("DEFAULT");

    spdlog::level::level_enum lvl;
    switch (level)
    {
        case LogLevel::Debug:
            lvl = spdlog::level::debug;
            break;
        case LogLevel::Info:
            lvl = spdlog::level::info;
            break;
        case LogLevel::Error:
            lvl = spdlog::level::err;
            break;
        case LogLevel::Off:
            lvl = spdlog::level::off;
            break;
        default:
            throw std::runtime_error("Unsupported LogLevel for Log");
    }

    s_logger->set_level(lvl);
}

}
