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

class Log
{
public:
    static std::shared_ptr<spdlog::logger>& instance();
    static void init();
};

}

#ifdef EMSCRIPTEN
#ifdef __DEBUG__
template<typename... Args>
static inline void LOG_DEBUG(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::instance()->trace(fmt, args...);
}
template<typename T>
static inline void LOG_DEBUG(const T& msg)
{
    Jackbengine::Log::instance()->trace(msg);
}
#else
#define LOG_DEBUG   void(0)
#endif
template<typename... Args>
static inline void LOG_INFO(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::instance()->info(fmt, args...);
}
template<typename T>
static inline void LOG_INFO(const T& msg)
{
    Jackbengine::Log::instance()->info(msg);
}
template<typename... Args>
static inline void LOG_ERROR(spdlog::string_view_t fmt, const Args &... args)
{
    Jackbengine::Log::instance()->error(fmt, args...);
}
template<typename T>
static inline void LOG_ERROR(const T& msg)
{
    Jackbengine::Log::instance()->error(msg);
}
#else
#ifdef __DEBUG__
#define LOG_DEBUG(...)  Jackbengine::Log::instance()->trace(__VA_ARGS__)
#else
#define LOG_DEBUG(...)  void(0)
#endif
#define LOG_INFO(...)   Jackbengine::Log::instance()->info(__VA_ARGS__)
#define LOG_ERROR(...)  Jackbengine::Log::instance()->error(__VA_ARGS__)
#endif

#endif // __LOG_H__
