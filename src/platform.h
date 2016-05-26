//
// platform.h
// Jackbengine
//
// Created by Damien Bendejacq on 26/05/2016.
// Copyright (c) 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "common.h"

NS_BEGIN_JKB

// Platform specific includes
#if defined(__APPLE__)
    #include "core/platform/osx.h"
#elif defined(WIN32)
    #include "core/platform/win32.h"
#endif

NS_END_JKB

#endif // __PLATFORM_H__
