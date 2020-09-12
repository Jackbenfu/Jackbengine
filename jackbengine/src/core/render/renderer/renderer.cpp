//
// renderer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
//

//#include "core/render/buffer/bufferLayout.h"
#include "renderer.h"
#include "glUtils.h"
#include "core/profile/profile.h"
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

Renderer::Renderer(const Window& window, TextureManager& textureManager, ShaderManager& shaderManager)
    : m_window {window},
      m_textureManager {textureManager},
      m_shaderManager {shaderManager}
{
    GL_CALL(glViewport(0, 0, m_window.width(), m_window.height()));
    GL_CALL(glClearColor(0, 0, 0, 1));
    GL_CALL(glEnable(GL_BLEND));
    GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    m_textureShader = m_shaderManager.load((const char*) texture_vertex_default_glsl, (const char*) texture_fragment_default_glsl);
    m_colorShader = m_shaderManager.load((const char*) color_vertex_default_glsl, (const char*) color_fragment_default_glsl);
    m_texture = m_textureManager.load(aquarelle_damien_square_alpha_png, aquarelle_damien_square_alpha_png_size);

    m_vao = std::make_unique<VertexArray>();

//    float vertices[] = {
//        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
//        1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
//        -1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
//        -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top left
//
//        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
//        0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
//        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
//        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top left
//    };
//    m_vbo = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));

//    GL_CALL(glEnableVertexAttribArray(0));
//    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*) nullptr));
//    GL_CALL(glEnableVertexAttribArray(1));
//    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*) (3 * sizeof(float))));
//    GL_CALL(glEnableVertexAttribArray(2));
//    GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*) (6 * sizeof(float))));

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
        4, 5, 7,
        5, 6, 7,
    };
    m_ibo = std::make_unique<IndexBuffer>(indices, sizeof(indices));

//    auto vboAttributes = {
//        VertexAttributeType::Float3,
//        VertexAttributeType::Float3,
//        VertexAttributeType::Float2,
//    };
}

void Renderer::clear()
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::present()
{
    SDL_GL_SwapWindow(m_window.nativeWindow());
}

void Renderer::colorTest() const
{
    PROFILE("Renderer::colorTest");

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

    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) nullptr));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float))));
    GL_CALL(glEnableVertexAttribArray(1));

    ShaderManager::bind(m_colorShader);

    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}

void Renderer::textureTest()
{
    PROFILE("Renderer::textureTest");

    ShaderManager::bind(m_textureShader);
    TextureManager::bind(m_texture);
    m_vao->bind();

    GL_CALL(glDrawElements(GL_TRIANGLES, m_ibo->count(), GL_UNSIGNED_INT, nullptr));
}

}
