//
// textureManager.h
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
//

#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <string>
#include <unordered_map>

#include "texture.h"

namespace Jackbengine::details {

class TextureManager
{
public:
    TextureManager() = default;
    ~TextureManager() = default;

    [[nodiscard]] unsigned int load(const std::string &file);
    [[nodiscard]] unsigned int load(const void *data, size_t dataSize);
    [[nodiscard]] static unsigned int load(const std::string &atlas, int dummy);

    void unload(unsigned int id);

    static void bind(unsigned int id);

private:
    [[nodiscard]] static unsigned generateId();

    std::unordered_map<unsigned int, std::unique_ptr<Texture>> m_textures;
};

}

#endif // __TEXTURE_MANAGER_H__
