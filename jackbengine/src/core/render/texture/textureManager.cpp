//
// textureManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
//

#include "textureManager.h"
#include "core/render/renderer/glUtils.h"

namespace Jackbengine::details {

unsigned int TextureManager::load(const std::string& file)
{
    const auto id = generateId();

    m_textures.emplace(id, std::make_unique<Texture>(id, file));

    return id;
}

unsigned int TextureManager::load(const void* data, size_t dataSize)
{
    const auto id = generateId();

    m_textures.emplace(id, std::make_unique<Texture>(id, data, dataSize));

    return id;
}

unsigned int TextureManager::load(const std::string&, /* TODO insert atlas info here */ int)
{
    return -1;
}

void TextureManager::unload(unsigned int id)
{
    GL_CALL(glDeleteTextures(1, &id));

    m_textures.erase(id);
}

void TextureManager::bind(unsigned int id)
{
    GL_CALL(glActiveTexture(GL_TEXTURE0));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, id));
}

unsigned int TextureManager::generateId()
{
    unsigned int id;
    GL_CALL(glGenTextures(1, &id));

    return id;
}

}
