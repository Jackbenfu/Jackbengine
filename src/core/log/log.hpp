//
// log.hpp
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __LOG_H__
#define __LOG_H__

#include <memory>
#include "common.hpp"
#include "spdlog/spdlog.h"

namespace Jackbengine {

class Log
{
DISALLOW_COPY_AND_MOVE(Log)

public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& getCoreLogger()
    {
        return s_coreLogger;
    }

    inline static std::shared_ptr<spdlog::logger>& getAppLogger()
    {
        return s_appLogger;
    }

private:
    static std::shared_ptr<spdlog::logger> s_coreLogger;
    static std::shared_ptr<spdlog::logger> s_appLogger;
};

}

#define LOG_CORE_INFO(...)     ::Jackbengine::Log::getCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)     ::Jackbengine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)    ::Jackbengine::Log::getCoreLogger()->error(__VA_ARGS__)
#define LOG_INFO(...)          ::Jackbengine::Log::getAppLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Jackbengine::Log::getAppLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Jackbengine::Log::getAppLogger()->error(__VA_ARGS__)

#if DEBUG
#define LOG_CORE_TRACE(...)    ::Jackbengine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define LOG_TRACE(...)         ::Jackbengine::Log::getAppLogger()->trace(__VA_ARGS__)
#else
#define LOG_CORE_TRACE(...)
#define LOG_TRACE(...)
#endif

#endif // __LOG_H__
