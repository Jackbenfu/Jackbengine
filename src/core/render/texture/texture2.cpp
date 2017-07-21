//
// texture2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include <core/tmx/tmxMap.hpp>
#include <core/render/font.hpp>
#include "texture2.hpp"
#include "texture2.impl.hpp"

using namespace Jackbengine;

Texture2::Texture2(const Renderer2& renderer, const std::string& file)
    : m_impl {std::make_unique<Impl>(renderer, file)}
{
    // Nothing
}

Texture2::Texture2(const Renderer2& renderer, const void *data, size_t dataSize)
    : m_impl {std::make_unique<Impl>(renderer, data, dataSize)}
{
    // Nothing
}

Texture2::Texture2(const Renderer2& renderer, int width, int height, Color color)
    : m_impl {std::make_unique<Impl>(renderer, width, height, color)}
{
    // Nothing
}

Texture2::Texture2(const Renderer2& renderer, const TmxMap& map, const TmxLayer& layer,
                   const void *tilesetImageData, size_t tilesetImageDataSize)
    : m_impl {std::make_unique<Impl>(renderer, map, layer, tilesetImageData, tilesetImageDataSize)}
{
    // Nothing
}

Texture2::Texture2(const Renderer2& renderer, const TmxMap& map, const TmxObjectGroup& objectGroup,
                   const void *tilesetImageData, size_t tilesetImageDataSize)
    : m_impl {std::make_unique<Impl>(renderer, map, objectGroup, tilesetImageData, tilesetImageDataSize)}
{
    // Nothing
}

Texture2::Texture2(const Renderer2& renderer, const Font2& font,
                   const std::string& text, Color foreground)
    : m_impl {std::make_unique<Impl>(renderer, font, text, foreground)}
{
    // Nothing
}

Texture2::~Texture2() = default;

int Texture2::getWidth() const
{
    return m_impl->getWidth();
}

int Texture2::getHeight() const
{
    return m_impl->getHeight();
}

void* Texture2::getInternalObject() const
{
    return m_impl->getInternalObject();
}
