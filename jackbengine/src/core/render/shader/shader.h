//
// glsl.h
// jackbengine
//
// Created by Damien Bendejacq on 13/11/2019.
//

#ifndef __SHADER_H__
#define __SHADER_H__

namespace Jackbengine::details {

class Shader
{
public:
    Shader(unsigned int id, const char *vertexShader, const char *fragmentShader, const char *glslVersion);
    ~Shader() = default;

private:
    static unsigned int compileShader(unsigned int type, const char *glslVersion, const char *source);

    unsigned int m_id {0};
};

}

#endif // __SHADER_H__
