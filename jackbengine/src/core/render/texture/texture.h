//
// texture.h
// jackbengine
//
// Created by Damien Bendejacq on 19/10/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>

#include "core/render/surface/surface.h"

namespace Jackbengine::details {

class Texture
{
public:
    Texture(unsigned int id, const std::string &file);
    Texture(unsigned int id, const void *data, size_t dataSize);
    ~Texture() = default;

    unsigned int id() const;

private:
    void loadTextureFromSurface(const Surface &surface);

    unsigned int m_id;
};

}

#endif // __TEXTURE_H__
