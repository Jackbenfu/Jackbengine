//
// log.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
//

#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Jackbengine {

std::shared_ptr<spdlog::logger>& Log::instance()
{
    static std::shared_ptr<spdlog::logger> instance;

    return instance;
}

void Log::init()
{
    spdlog::set_pattern("%^[%D %T.%e] [%P] [%t] [%n] [%l] %v%$");
    instance() = spdlog::stdout_color_mt("DEFAULT");
    instance()->set_level(spdlog::level::trace);
}

}
