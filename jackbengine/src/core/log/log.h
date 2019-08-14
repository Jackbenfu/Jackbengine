//
// log.h
// jackbengine
//
// Created by Damien Bendejacq on 22/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __LOG_H__
#define __LOG_H__

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#include <memory>
#include "common.h"
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#ifdef __DEBUG__
#define LOG_TRACE(...)  EM_ASM(console.debug(__VA_ARGS__);)
#else
#define LOG_TRACE
#endif
#define LOG_INFO(...)   EM_ASM(console.info(__VA_ARGS__);)
#define LOG_ERROR(...)  EM_ASM(console.error(__VA_ARGS__);)
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
