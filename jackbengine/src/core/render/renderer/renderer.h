//
// renderer.h
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __GL_RENDERER_H__
#define __GL_RENDERER_H__

#include "core/render/surface/surface.h"
#include "core/render/window/window.h"
#include "core/render/texture/textureManager.h"
#include "core/render/shader/shaderManager.h"

typedef int GLint;
typedef unsigned int GLenum;

namespace Jackbengine::details {

class Renderer
{
public:
    explicit Renderer(const Window &window, TextureManager &textureManager, ShaderManager &shaderManager);
    ~Renderer() = default;

    static void clear();
    void present();

    void colorTest();
    void textureTest();
    void renderToTextureTest();

private:
    const Window &m_window;
    TextureManager &m_textureManager;
    ShaderManager &m_shaderManager;

    unsigned int m_textureShader {0};
    unsigned int m_colorShader {0};
    unsigned int m_texture {0};
};

}

#endif // __GL_RENDERER_H__
