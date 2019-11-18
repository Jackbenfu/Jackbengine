//
// texture.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "texture.h"
#include "core/render/renderer/glUtils.h"
#include "core/sdl/sdlinc.h"
#include "core/io/rwops.h"
#include "core/render/surface/surface.h"

namespace Jackbengine::details {

Texture::Texture(unsigned int id, const std::string &file)
    : m_id {id}
{
    const Surface surface(file);

    loadTextureFromSurface(surface);
}

Texture::Texture(unsigned int id, const void *data, size_t dataSize)
    : m_id {id}
{
    const RWops rwops(data, dataSize);
    const Surface surface(rwops);

    loadTextureFromSurface(surface);
}

unsigned int Texture::id() const
{
    return m_id;
}

void Texture::loadTextureFromSurface(const Surface &surface)
{
    const auto nativeSurface = surface.nativeObject();

    GLint internalFormat;
    GLenum format;

    /*
     * Desktop > bbp=4, rmask=0x00ff0000, format=GL_BGRA
     * WebGL   > bbp=3, rmask=0x000000ff, format=GL_RGB
     */
    if (nativeSurface->format->BytesPerPixel == 4)
    {
        internalFormat = GL_RGBA;
#ifdef EMSCRIPTEN
        format = GL_RGBA;
#else
        format = nativeSurface->format->Rmask == 0xff ? GL_RGBA : GL_BGRA;
#endif
    }
    else // assume bbp = 3
    {
        internalFormat = GL_RGB;
#ifdef EMSCRIPTEN
        format = GL_RGB;
#else
        format = nativeSurface->format->Rmask == 0xff ? GL_RGB : GL_BGR;
#endif
    }

    GL_CALL(glBindTexture(GL_TEXTURE_2D, m_id));

    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    GL_CALL(glTexImage2D(
        GL_TEXTURE_2D,
        0,
        internalFormat,
        nativeSurface->w,
        nativeSurface->h,
        0,
        format,
        GL_UNSIGNED_BYTE,
        nativeSurface->pixels
    ));
}

}
