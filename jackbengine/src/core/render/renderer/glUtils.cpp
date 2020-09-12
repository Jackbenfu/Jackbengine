//
// glUtils.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
//

#include <string>

#include "glUtils.h"
#include "core/log/log.h"

namespace Jackbengine::details {

void logGlError([[maybe_unused]] const char* func, [[maybe_unused]] const char* file, [[maybe_unused]] int line)
{
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR)
    {
        std::string type;
        switch (error)
        {
            case GL_INVALID_ENUM:
                type = "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                type = "INVALID_VALUE";
                break;
            case GL_INVALID_OPERATION:
                type = "INVALID_OPERATION";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                type = "INVALID_FRAMEBUFFER_OPERATION";
                break;
            case GL_OUT_OF_MEMORY:
                type = "OUT_OF_MEMORY";
                break;
            default:
                LOG_ERROR("Unhandled OpenGL error code={}", error);
                break;
        }

        LOG_ERROR("Handled OpenGL error code={}, type={}, function={}, location={}({})", error, type, func, file, line);
    }
}

[[maybe_unused]] const char* glEnumName(GLenum enumName)
{
    switch (enumName)
    {
        case GL_RGB:
            return "GL_RGB";
        case GL_RGBA:
            return "GL_RGBA";
#ifndef EMSCRIPTEN
        case GL_BGR:
            return "GL_BGR";
        case GL_BGRA:
            return "GL_BGRA";
#endif
        default:
            throw std::runtime_error(fmt::format("Unsupported GLenum value {}", enumName));
    }
}

}
