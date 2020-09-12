//
// log.h
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
//

#ifndef __LOG_H__
#define __LOG_H__

#include "spdlog/spdlog.h"

namespace Jackbengine {

enum class LogLevel
{
    Debug,
    Info,
    Error,
    Off,
};

class Log
{
public:
    static void init(LogLevel level);

    inline static std::shared_ptr<spdlog::logger>& logger()
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
static inline void LOG_DEBUG(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::logger()->debug(fmt, args...);
}
template<typename T>
static inline void LOG_DEBUG(const T& msg)
{
    Jackbengine::Log::logger()->debug(msg);
}
#else
#define LOG_DEBUG
#endif
template<typename... Args>
static inline void LOG_INFO(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::logger()->info(fmt, args...);
}
template<typename T>
static inline void LOG_INFO(const T& msg)
{
    Jackbengine::Log::logger()->info(msg);
}
template<typename... Args>
static inline void LOG_ERROR(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::logger()->error(fmt, args...);
}
template<typename T>
static inline void LOG_ERROR(const T& msg)
{
    Jackbengine::Log::logger()->error(msg);
}
#else
#ifdef __DEBUG__
#define LOG_DEBUG(...)  Jackbengine::Log::logger()->debug(__VA_ARGS__)
#else
#define LOG_DEBUG(...)
#endif
#define LOG_INFO(...)   Jackbengine::Log::logger()->info(__VA_ARGS__)
#define LOG_ERROR(...)  Jackbengine::Log::logger()->error(__VA_ARGS__)
#endif

#endif // __LOG_H__
