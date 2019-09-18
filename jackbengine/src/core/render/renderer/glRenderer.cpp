//
// glRenderer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "glad/glad.h"

#include "glRenderer.h"
#include "core/sdl/sdlinc.h"
#include "core/resource/importResource.h"
#include "core/log/log.h"

IMPORT_TEXT_RESOURCE(defaultVertex_glsl)
IMPORT_TEXT_RESOURCE(defaultFragment_glsl)

namespace Jackbengine::details {

#ifdef __RELEASE__
#define GL_CALL(f) f
#else
#define GL_CALL(f) f;\
                    logError(#f, __FILE__, __LINE__)
#endif

GlRenderer::GlRenderer(const Window &window)
    : m_window {window}
{
    GL_CALL(glViewport(0, 0, m_window.width(), m_window.height()));
    GL_CALL(glClearColor(0, 0, 0, 1));
}

GlRenderer::~GlRenderer()
{
    GL_CALL(glDeleteProgram(m_program));
}

void GlRenderer::clear()
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

void GlRenderer::present()
{
    SDL_GL_SwapWindow(m_window.nativeWindow());
}

void GlRenderer::initTest()
{
    float positions[] = {
        -0.5f, -0.5f,   // 0
        0.5f, -0.5f,    // 1
        0.5f, 0.5f,     // 2
        -0.5f, 0.5f,    // 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,
    };

    unsigned int va;
    GL_CALL(glGenVertexArrays(1, &va));
    GL_CALL(glBindVertexArray(va));

    unsigned int vbo;
    GL_CALL(glGenBuffers(1, &vbo));

    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr));

    unsigned int ibo;
    GL_CALL(glGenBuffers(1, &ibo));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

    m_program = createProgram(defaultVertex_glsl, defaultFragment_glsl);

    GL_CALL(glUseProgram(m_program));
}

void GlRenderer::test()
{
    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}

unsigned int GlRenderer::createProgram(const char *vertexShader, const char *fragmentShader)
{
    const auto program = GL_CALL(glCreateProgram());
    const auto vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    const auto fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GL_CALL(glAttachShader(program, vs));
    GL_CALL(glAttachShader(program, fs));
    GL_CALL(glLinkProgram(program));
    GL_CALL(glValidateProgram(program));

    GL_CALL(glDetachShader(program, vs));
    GL_CALL(glDetachShader(program, fs));

    return program;
}

unsigned int GlRenderer::compileShader(unsigned int type, const char *source)
{
    const auto shader = GL_CALL(glCreateShader(type));
    GL_CALL(glShaderSource(shader, 1, &source, nullptr));
    GL_CALL(glCompileShader(shader));

    int result;
    GL_CALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE)
    {
        int length;
        GL_CALL(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
        const auto message = (char *) alloca(length * sizeof(char));
        GL_CALL(glGetShaderInfoLog(shader, length, &length, message));

        GL_CALL(glDeleteShader(shader));

        throw std::runtime_error(message);
    }

    return shader;
}

void GlRenderer::logError(const char *function, const char *file, int line)
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

        LOG_ERROR("Handled OpenGL error code={}, type={}, function={}, location={}({})", error, type, function, file, line);
    }
}

}
