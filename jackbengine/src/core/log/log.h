//
// log.h
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __LOG_H__
#define __LOG_H__

#include "spdlog/spdlog.h"

namespace Jackbengine {

class Log
{
public:
    static void init();

    inline static std::shared_ptr<spdlog::logger> &getLogger()
    {
        return s_logger;
    }

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};

}

#ifdef EMSCRIPTEN
#ifdef __DEBUG__
template<typename... Args>
static inline void LOG_TRACE(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::getLogger()->trace(fmt, args...);
}
template<typename T>
static inline void LOG_TRACE(const T& msg)
{
    Jackbengine::Log::getLogger()->trace(msg);
}
#else
#define LOG_TRACE
#endif
template<typename... Args>
static inline void LOG_INFO(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::getLogger()->info(fmt, args...);
}
template<typename T>
static inline void LOG_INFO(const T& msg)
{
    Jackbengine::Log::getLogger()->info(msg);
}
template<typename... Args>
static inline void LOG_ERROR(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::getLogger()->error(fmt, args...);
}
template<typename T>
static inline void LOG_ERROR(const T& msg)
{
    Jackbengine::Log::getLogger()->error(msg);
}
#else
#ifdef __DEBUG__
#define LOG_TRACE(...)  Jackbengine::Log::getLogger()->trace(__VA_ARGS__)
#else
#define LOG_TRACE(...)
#endif
#define LOG_INFO(...)   Jackbengine::Log::getLogger()->info(__VA_ARGS__)
#define LOG_ERROR(...)  Jackbengine::Log::getLogger()->error(__VA_ARGS__)
#endif

#endif // __LOG_H__
