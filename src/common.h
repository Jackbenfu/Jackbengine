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

#endif // __COMMON_H__
