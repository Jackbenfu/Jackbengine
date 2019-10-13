//
// glRenderer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifdef EMSCRIPTEN
#include <GLES3/gl3.h>
#else

#include "glad/glad.h"

#endif

#include "glRenderer.h"
#include "core/sdl/sdlinc.h"
#include "core/render/surface/surface.h"
#include "core/resource/importResource.h"
#include "core/log/log.h"

IMPORT_TEXT_RESOURCE(color_vertex_default_glsl)
IMPORT_TEXT_RESOURCE(color_fragment_default_glsl)
IMPORT_TEXT_RESOURCE(texture_vertex_default_glsl)
IMPORT_TEXT_RESOURCE(texture_fragment_default_glsl)
IMPORT_TEXT_RESOURCE(texture_fragment_grayscale_glsl)
IMPORT_BINARY_RESOURCE(aquarelle_damien_square_png)
IMPORT_BINARY_RESOURCE(aquarelle_damien_square_alpha_png)

namespace Jackbengine::details {

#ifdef __RELEASE__
#define GL_CALL(f) f
#else
#define GL_CALL(f)  f;\
                    logGlError(#f, __FILE__, __LINE__)
#endif

GlRenderer::GlRenderer(const Window &window)
    : m_window {window}
{
#ifdef EMSCRIPTEN
    m_glslVersion = "#version 300 es";
#else
    m_glslVersion = "#version 330 core";
#endif

    GL_CALL(glViewport(0, 0, m_window.width(), m_window.height()));
    GL_CALL(glClearColor(0, 0, 0, 1));

    GL_CALL(glEnable(GL_BLEND));
    GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

//    auto rwops = RWops(aquarelle_damien_square_png, aquarelle_damien_square_png_size);
    auto rwops = RWops(aquarelle_damien_square_alpha_png, aquarelle_damien_square_alpha_png_size);
    m_textureSurface = std::make_unique<Surface>(rwops);

    const auto surfaceFormat = m_textureSurface->nativeObject()->format;

    /*
     * Desktop > bbp=4, rmask=0x00ff0000, format=GL_BGRA
     * WebGL   > bbp=3, rmask=0x000000ff, format=GL_RGB
     */
    if (surfaceFormat->BytesPerPixel == 4)
    {
        m_internalFormat = GL_RGBA;
#ifdef EMSCRIPTEN
        m_format = GL_RGBA;
#else
        m_format = surfaceFormat->Rmask == 0xff ? GL_RGBA : GL_BGRA;
#endif
    }
    else // assume bbp = 3
    {
        m_internalFormat = GL_RGB;
#ifdef EMSCRIPTEN
        m_format = GL_RGB;
#else
        m_format = surfaceFormat->Rmask == 0xff ? GL_RGB : GL_BGR;
#endif
    }

    int maxElementVertices;
    glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &maxElementVertices);
    LOG_INFO("{}", maxElementVertices);
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

void GlRenderer::colorTest()
{
    float vertices[] = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
    };

    unsigned int vao;
    GL_CALL(glGenVertexArrays(1, &vao));
    GL_CALL(glBindVertexArray(vao));

    unsigned int vbo;
    GL_CALL(glGenBuffers(1, &vbo));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

    unsigned int ibo;
    GL_CALL(glGenBuffers(1, &ibo));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW));

    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float))));
    GL_CALL(glEnableVertexAttribArray(1));

    m_program = createProgram((const char *) color_vertex_default_glsl, (const char *) color_fragment_default_glsl);
    GL_CALL(glUseProgram(m_program));

    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void GlRenderer::textureTest()
{
    float vertices[] = {
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
        -1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top left

        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top left
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
        4, 5, 7,
        5, 6, 7,
    };

    unsigned int vao;
    GL_CALL(glGenVertexArrays(1, &vao));
    GL_CALL(glBindVertexArray(vao));

    unsigned int vbo;
    GL_CALL(glGenBuffers(1, &vbo));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

    unsigned int ibo;
    GL_CALL(glGenBuffers(1, &ibo));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW));

    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float))));
    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float))));
    GL_CALL(glEnableVertexAttribArray(2));

    GL_CALL(glGenTextures(1, &m_texture));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_texture));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

#ifdef EMSCRIPTEN
    GL_CALL(glTexImage2D(
        GL_TEXTURE_2D,
        0,
        m_internalFormat,
        m_textureSurface->nativeObject()->w,
        m_textureSurface->nativeObject()->h,
        0,
        m_format,
        GL_UNSIGNED_BYTE,
        m_textureSurface->nativeObject()->pixels
    ));
#else
    GL_CALL(glTexImage2D(
        GL_TEXTURE_2D,
        0,
        m_internalFormat,
        m_textureSurface->nativeObject()->w,
        m_textureSurface->nativeObject()->h,
        0,
        m_format,
        GL_UNSIGNED_BYTE,
        m_textureSurface->nativeObject()->pixels
    ));
#endif

    m_program = createProgram((const char *) texture_vertex_default_glsl, (const char *) texture_fragment_default_glsl);
    GL_CALL(glUseProgram(m_program));

    GL_CALL(glActiveTexture(GL_TEXTURE0));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_texture));

    GL_CALL(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0));
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
    const GLchar *sourceWithVersion[3] = {m_glslVersion, "\n", source};

    GL_CALL(glShaderSource(shader, 3, sourceWithVersion, nullptr));
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

        const char *typeS;
        switch (type)
        {
            case GL_VERTEX_SHADER:
                typeS = "GL_VERTEX_SHADER";
                break;
            case GL_FRAGMENT_SHADER:
                typeS = "GL_FRAGMENT_SHADER";
                break;
            default:
                typeS = std::to_string(type).c_str();
        }

        LOG_INFO("{} {}", typeS, message);

        throw std::runtime_error(message);
    }

    return shader;
}

void GlRenderer::logGlError([[maybe_unused]] const char *func, [[maybe_unused]] const char *file, [[maybe_unused]] int line)
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

const char *GlRenderer::glEnumName(GLenum enumName)
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
            throw new std::runtime_error(fmt::format("Unsupported GLenum value {}", enumName));
    }
}

}
