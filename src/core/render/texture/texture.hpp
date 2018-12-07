//
// texture.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <memory>
#include "core/render/color.hpp"
#include "core/render/font/font.hpp"

namespace Jackbengine {

class Renderer;

class Texture
{
    friend class Renderer;

DISALLOW_COPY_AND_MOVE(Texture)

public:
    Texture(const Renderer& renderer, const std::string& file);
    Texture(const Renderer& renderer, const void *data, size_t dataSize);
    Texture(const Renderer& renderer, int width, int height, Color color);
    Texture(const Renderer& renderer, const Font& font, const std::string& text, Color foreground);

    ~Texture();

    int width() const;
    int height() const;

private:
    void *internalObject() const;

    class Impl;

    std::unique_ptr<Impl> m_impl;
};

}

#endif // __TEXTURE_H__
