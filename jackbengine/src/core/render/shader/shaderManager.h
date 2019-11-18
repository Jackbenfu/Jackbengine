//
// shaderManager.h
// jackbengine
//
// Created by Damien Bendejacq on 13/11/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __SHADER_MANAGER_H__
#define __SHADER_MANAGER_H__

#include <unordered_map>

#include "shader.h"

namespace Jackbengine::details {

class ShaderManager
{
public:
    ShaderManager() = default;
    ~ShaderManager() = default;

    unsigned int load(const char *vertexShader, const char *fragmentShader);

    void unload(unsigned int id);

    static void bind(unsigned int id);

private:
    int generateId() const;

    std::unordered_map<unsigned int, std::unique_ptr<Shader>> m_shaders;

#ifdef EMSCRIPTEN
    const char *m_glslVersion = "#version 300 es";
#else
    const char *m_glslVersion = "#version 330 core";
#endif
};

}

#endif // __SHADER_MANAGER_H__
