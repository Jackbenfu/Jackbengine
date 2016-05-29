//
//  common.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 28/01/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COMMON_H__
#define __COMMON_H__

// Types shortcuts
using uint = unsigned int;
using ushort = unsigned short;
using byte = unsigned char;

// Compiler macros
#define UNUSED(a)       (void)a;

// Mathematic macros
#define MAX(a, b)       ((a > b) ? a : b)
#define MIN(a, b)       ((a < b) ? a : b)

// Memory allocation/deallocation macros
#define DELETE_SAFE(p)          if (p) { delete p; p = nullptr; }
#define DELETE_SAFE_ARRAY(p)    if (p) { delete[] p; p = nullptr; }

// Namespaces
#define NS_BEGIN_JKB    namespace Jackbengine {
#define NS_END_JKB      } using namespace Jackbengine;
#define NS_STD          using namespace std;

// Logging macros
#include <stdio.h>
#include <time.h>
#include <string.h>
#define LOG(fd, level, message, ...)                                \
    {                                                               \
        char *slash = strrchr(__FILE__, '/');                       \
                                                                    \
        auto DATE_BUFFER_SIZE = 64;                                 \
        char dateBuffer[DATE_BUFFER_SIZE];                          \
        time_t rawTime;                                             \
        struct tm *timeInfo;                                        \
        time(&rawTime);                                             \
        timeInfo = localtime(&rawTime);                             \
        strftime(dateBuffer, DATE_BUFFER_SIZE, "%c", timeInfo);     \
                                                                    \
        fprintf(fd, "[%s] [%-5s] [%s] [%3d] ",                      \
            dateBuffer,                                             \
            level,                                                  \
            slash ? slash + 1 : __FILE__,                           \
            __LINE__                                                \
        );                                                          \
        fprintf(fd, message, ##__VA_ARGS__);                        \
        fprintf(fd, "\n");                                          \
        fflush(fd);                                                 \
    }

#define LOG_ERROR(message, ...)     LOG(stderr, "ERROR", message, ##__VA_ARGS__)
#define LOG_DEBUG(message, ...)     LOG(stdout, "DEBUG", message, ##__VA_ARGS__)
#define LOG_INFO (message, ...)     LOG(stdout, "INFO",  message, ##__VA_ARGS__)

#endif // __COMMON_H__
