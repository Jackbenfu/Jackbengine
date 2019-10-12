//
// glRenderer.h
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __GL_RENDERER_H__
#define __GL_RENDERER_H__

#include "core/render/surface/surface.h"
#include "core/render/window/window.h"

typedef int GLint;
typedef unsigned int GLenum;

namespace Jackbengine::details {

class GlRenderer
{
public:
    explicit GlRenderer(const Window &window);
    ~GlRenderer();

    static void clear();
    void present();

    void colorTest();
    void textureTest();

private:
    unsigned int createProgram(const char *vertexShader, const char *fragmentShader);
    unsigned int compileShader(unsigned int type, const char *source);

    static void logGlError(const char *func, const char *file, int line);
    static const char *glEnumName(GLenum enumName);

    const Window &m_window;
    const char *m_glslVersion;
    unsigned int m_program {0};
    unsigned int m_texture {0};
    std::unique_ptr<Surface> m_textureSurface;

    GLint m_internalFormat;
    GLenum m_format;
};

}

#endif // __GL_RENDERER_H__
