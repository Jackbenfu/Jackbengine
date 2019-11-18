//
// textureManager.h
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
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

    unsigned int load(const std::string &file);
    unsigned int load(const void *data, size_t dataSize);
    unsigned int load(const std::string &atlas, int dummy);

    void unload(unsigned int id);

    static void bind(unsigned int id);

private:
    int generateId() const;

    std::unordered_map<unsigned int, std::unique_ptr<Texture>> m_textures;
};

}

#endif // __TEXTURE_MANAGER_H__
