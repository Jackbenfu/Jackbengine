//
// renderer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "renderer.h"
#include "glUtils.h"
#include "core/log/tracer.h"
#include "core/sdl/sdlinc.h"
#include "core/render/surface/surface.h"
#include "core/resource/importResource.h"

IMPORT_TEXT_RESOURCE(color_vertex_default_glsl)
IMPORT_TEXT_RESOURCE(color_fragment_default_glsl)
IMPORT_TEXT_RESOURCE(texture_vertex_default_glsl)
IMPORT_TEXT_RESOURCE(texture_fragment_default_glsl)
IMPORT_TEXT_RESOURCE(texture_fragment_grayscale_glsl)
IMPORT_TEXT_RESOURCE(texture_fragment_pixelate_glsl)
IMPORT_BINARY_RESOURCE(aquarelle_damien_square_png)
IMPORT_BINARY_RESOURCE(aquarelle_damien_square_alpha_png)

namespace Jackbengine::details {

Renderer::Renderer(const Window &window, TextureManager &textureManager, ShaderManager &shaderManager)
    : m_window {window},
      m_textureManager {textureManager},
      m_shaderManager {shaderManager}
{
    GL_CALL(glViewport(0, 0, m_window.width(), m_window.height()));
    GL_CALL(glClearColor(0, 0, 0, 1));
    GL_CALL(glEnable(GL_BLEND));
    GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    m_textureShader = m_shaderManager.load((const char *) texture_vertex_default_glsl, (const char *) texture_fragment_pixelate_glsl);
    m_colorShader = m_shaderManager.load((const char *) color_vertex_default_glsl, (const char *) color_fragment_default_glsl);
    m_texture = m_textureManager.load(aquarelle_damien_square_alpha_png, aquarelle_damien_square_alpha_png_size);
}

void Renderer::clear()
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::present()
{
    SDL_GL_SwapWindow(m_window.nativeWindow());
}

void Renderer::colorTest()
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

    m_shaderManager.bind(m_colorShader);

    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void Renderer::textureTest()
{
    TRACE("Renderer::textureTest");

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

    m_shaderManager.bind(m_textureShader);
    GL_CALL(glUniform1f(glGetUniformLocation(m_textureShader, "uPixelResolution"), 92));

    m_textureManager.bind(m_texture);

    GL_CALL(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0));
}

void Renderer::renderToTextureTest()
{
//    m_program = createProgram((const char *) texture_vertex_default_glsl, (const char *) texture_fragment_pixelate_glsl, m_glslVersion);
//    GL_CALL(glUseProgram(m_program));
//
//    float vertices[] = {
//        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
//        0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
//        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
//        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top left
//    };
//
//    unsigned int indices[] = {
//        0, 1, 3,
//        1, 2, 3,
//    };
//
//    unsigned int vao;
//    GL_CALL(glGenVertexArrays(1, &vao));
//    GL_CALL(glBindVertexArray(vao));
//
//    unsigned int vbo;
//    GL_CALL(glGenBuffers(1, &vbo));
//    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
//    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));
//
//    unsigned int ibo;
//    GL_CALL(glGenBuffers(1, &ibo));
//    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
//    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW));
//
//    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0));
//    GL_CALL(glEnableVertexAttribArray(0));
//    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float))));
//    GL_CALL(glEnableVertexAttribArray(1));
//    GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float))));
//    GL_CALL(glEnableVertexAttribArray(2));
//
//    GL_CALL(glUniform1f(glGetUniformLocation(m_program, "uPixelResolution"), 92));
//
//    unsigned int fbo;
//    GL_CALL(glGenFramebuffers(1, &fbo));
//    GL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, fbo));
//
//    GL_CALL(glGenTextures(1, &m_texture));
//    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_texture));
//    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
//    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
//    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
//    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
//
//#ifdef EMSCRIPTEN
//    GL_CALL(glTexImage2D(
//        GL_TEXTURE_2D,
//        0,
//        m_internalFormat,
//        m_textureSurface->nativeObject()->w,
//        m_textureSurface->nativeObject()->h,
//        0,
//        m_format,
//        GL_UNSIGNED_BYTE,
//        0
//    ));
//#else
//    GL_CALL(glTexImage2D(
//        GL_TEXTURE_2D,
//        0,
//        m_internalFormat,
//        m_textureSurface->nativeObject()->w,
//        m_textureSurface->nativeObject()->h,
//        0,
//        m_format,
//        GL_UNSIGNED_BYTE,
//        0
//    ));
//#endif
//
//    GL_CALL(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture, 0));
//    GLenum drawBuffer[1] = {GL_COLOR_ATTACHMENT0};
//    GL_CALL(glDrawBuffers(1, drawBuffer));
//
//    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//    {
//        return;
//    }
//
////    GL_CALL(glViewport(0, 0, m_window.width(), m_window.height()));
//
//    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//    GL_CALL(glActiveTexture(GL_TEXTURE0));
//    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_texture));
//    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
//
//    GL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
//    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//    GL_CALL(glActiveTexture(GL_TEXTURE0));
//    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_texture));
//    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

}
