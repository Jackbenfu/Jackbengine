//
// glsl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/11/2019.
//

#include <stdexcept>
#include <string>

#include "core/render/renderer/glUtils.h"
#include "shader.h"
#include "core/log/log.h"

namespace Jackbengine::details {

Shader::Shader(unsigned int id, const char *vertexShader, const char *fragmentShader, const char *glslVersion)
    : m_id {id}
{
    const auto vs = compileShader(GL_VERTEX_SHADER, vertexShader, glslVersion);
    const auto fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader, glslVersion);

    GL_CALL(glAttachShader(m_id, vs));
    GL_CALL(glAttachShader(m_id, fs));
    GL_CALL(glLinkProgram(m_id));
    GL_CALL(glValidateProgram(m_id));

    GL_CALL(glDetachShader(m_id, vs));
    GL_CALL(glDetachShader(m_id, fs));
}

unsigned int Shader::compileShader(unsigned int type, const char *source, const char *glslVersion)
{
    const auto shader = GL_CALL(glCreateShader(type));
    const GLchar *sourceWithVersion[3] = {glslVersion, "\n", source};

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

        LOG_ERROR("{} {}", typeS, message);

        throw std::runtime_error(message);
    }

    return shader;
}

}
