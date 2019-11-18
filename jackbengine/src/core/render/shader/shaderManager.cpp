//
// shaderManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/11/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "shaderManager.h"
#include "core/render/renderer/glUtils.h"

namespace Jackbengine::details {

unsigned int ShaderManager::load(const char *vertexShader, const char *fragmentShader)
{
    const auto id = generateId();

    m_shaders.emplace(id, std::make_unique<Shader>(id, vertexShader, fragmentShader, m_glslVersion));

    return id;
}

void ShaderManager::unload(unsigned int id)
{
    GL_CALL(glDeleteProgram(id));

    m_shaders.erase(id);
}

void ShaderManager::bind(unsigned int id)
{
    GL_CALL(glUseProgram(id));
}

int ShaderManager::generateId() const
{
    unsigned int id;
    id = GL_CALL(glCreateProgram());

    return id;
}

}
