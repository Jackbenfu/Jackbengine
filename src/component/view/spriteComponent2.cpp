//
// spriteComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 02/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "spriteComponent2.hpp"

using namespace Jackbengine;

SpriteComponent2::SpriteComponent2(const Renderer2& renderer, const std::string& file)
    : m_texture {renderer, file}
{
    // Nothing
}

SpriteComponent2::SpriteComponent2(const Renderer2& renderer, const void *data, size_t dataSize)
    : m_texture {renderer, data, dataSize}
{
    // Nothing
}

SpriteComponent2::SpriteComponent2(const Renderer2& renderer, int width, int height, Color color)
    : m_texture {renderer, width, height, color}
{
    // Nothing
}

SpriteComponent2::SpriteComponent2(const Renderer2& renderer, const TmxMap& map, const TmxLayer& layer,
                                   const void *tilesetImageData, size_t tilesetImageDataSize)
    : m_texture {renderer, map, layer, tilesetImageData, tilesetImageDataSize}
{
    // Nothing
}

SpriteComponent2::SpriteComponent2(const Renderer2& renderer, const TmxMap& map, const TmxObjectGroup& objectGroup,
                                   const void *tilesetImageData, size_t tilesetImageDataSize)
    : m_texture {renderer, map, objectGroup, tilesetImageData, tilesetImageDataSize}
{
    // Nothing
}

const Texture2& SpriteComponent2::getTexture() const
{
    return m_texture;
}
