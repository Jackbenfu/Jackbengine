//
// renderer.h
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
//

#ifndef __GL_RENDERER_H__
#define __GL_RENDERER_H__

#include "core/render/surface/surface.h"
#include "core/render/window/window.h"
#include "core/render/texture/textureManager.h"
#include "core/render/shader/shaderManager.h"

#include "core/render/buffer/vertexBuffer.h"
#include "core/render/buffer/indexBuffer.h"
#include "core/render/buffer/vertexArray.h"

namespace Jackbengine::details {

class Renderer
{
public:
    explicit Renderer(const Window& window, TextureManager& textureManager, ShaderManager& shaderManager);
    ~Renderer() = default;

    static void clear();
    void present();

    void colorTest() const;
    void textureTest();

private:
    const Window& m_window;
    TextureManager& m_textureManager;
    ShaderManager& m_shaderManager;

    unsigned int m_textureShader {0};
    unsigned int m_colorShader {0};
    unsigned int m_texture {0};

    std::unique_ptr<VertexArray> m_vao;
    std::unique_ptr<VertexBuffer> m_vbo;
    std::unique_ptr<IndexBuffer> m_ibo;
};

}

#endif // __GL_RENDERER_H__
