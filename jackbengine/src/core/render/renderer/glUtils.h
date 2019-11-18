//
// glUtils.h
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __GL_UTILS_H__
#define __GL_UTILS_H__

namespace Jackbengine::details {

#ifdef EMSCRIPTEN
#include <GLES3/gl3.h>
#else

#include "glad/glad.h"

#endif

#ifdef __RELEASE__
#define GL_CALL(f) f
#else
#define GL_CALL(f)  f;\
                    logGlError(#f, __FILE__, __LINE__)
#endif

void logGlError(const char *func, const char *file, int line);
const char *getGlEnumName(GLenum enumName);

}

#endif // __GL_UTILS_H__
