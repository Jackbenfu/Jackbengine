//
// spriteComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 02/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "spriteComponent.hpp"

namespace Jackbengine {

SpriteComponent::SpriteComponent(const Renderer& renderer, const std::string& file)
    : m_texture {std::make_unique<Texture>(renderer, file)}
{
}

SpriteComponent::SpriteComponent(const Renderer& renderer, const void *data, size_t dataSize)
    : m_texture {std::make_unique<Texture>(renderer, data, dataSize)}
{
}

SpriteComponent::SpriteComponent(const Renderer& renderer, int width, int height, Color color)
    : m_texture {std::make_unique<Texture>(renderer, width, height, color)}
{
}

const Texture& SpriteComponent::texture() const
{
    return *m_texture;
}

}
