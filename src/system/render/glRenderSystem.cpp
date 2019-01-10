//
// glRenderSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 30/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifdef EMSCRIPTEN
#include <GLES2/gl2.h>
#endif

#ifndef EMSCRIPTEN
#include <GL/glew.h>
#endif

#include "glRenderSystem.hpp"
#include "component/view/spriteComponent.hpp"
#include "component/body/transformComponent.hpp"
#include "component/layout/zIndexComponent.hpp"

namespace Jackbengine {

GlRenderSystem::GlRenderSystem(const Window& window)
    : m_window {window}
{
#ifndef EMSCRIPTEN
    const auto glewStatus = glewInit();
    if (glewStatus != GLEW_OK)
    {
        throw std::runtime_error((const char *) glewGetErrorString(glewStatus));
    }
#endif

    float positions[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f,
    };

#ifndef EMSCRIPTEN
    uint va;
    glGenVertexArrays(1, &va);
    glBindVertexArray(va);
#endif

    uint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

    const std::string vertexShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";
    const std::string fragmentShader =
        "#version 330 core\n"
        "\n"
        "out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

    program = createProgram(vertexShader, fragmentShader);
    glUseProgram(program);

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}

GlRenderSystem::~GlRenderSystem()
{
    glDeleteProgram(program);
}

int GlRenderSystem::order() const
{
    return (int) SystemOrder::SpriteRender;
}

void GlRenderSystem::frame(float)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(m_window.m_window);
}

bool GlRenderSystem::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<SpriteComponent>()
           && components.any<TransformComponent>()
           && components.any<ZIndexComponent>();
}

void GlRenderSystem::sortByZIndex()
{
    const auto lambda = [](
        const std::pair<Entity, ComponentCollection *>& left,
        const std::pair<Entity, ComponentCollection *>& right
    )
    {
        const auto leftZIndex = left.second->get<ZIndexComponent>();
        const auto rightZIndex = right.second->get<ZIndexComponent>();

        return leftZIndex->index() < rightZIndex->index();
    };

    sort(lambda);
}

uint GlRenderSystem::createProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
    const auto program = glCreateProgram();
    const auto vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    const auto fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDetachShader(program, vs);
    glDetachShader(program, fs);

    return program;
}

uint GlRenderSystem::compileShader(uint type, const std::string& source)
{
    const auto shader = glCreateShader(type);
    const auto src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int result;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        const auto message = (char *) alloca(length * sizeof(char));
        glGetShaderInfoLog(shader, length, &length, message);

        glDeleteShader(shader);

        throw std::runtime_error(message);
    }

    return shader;
}

}
