//
//  spriteComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 25/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "spriteComponent.h"

SpriteComponent::SpriteComponent()
{
}

SpriteComponent::~SpriteComponent()
{
    DELETE_SAFE(m_texture);
}

bool SpriteComponent::loadFromFile(const Renderer *renderer, const char *file)
{
    bool result = false;

    if (!m_texture)
    {
        m_texture = Texture::create();
        if (m_texture->loadFromFile(renderer, file))
        {
            result = true;
        }
    }

    return result;
}

bool SpriteComponent::loadFromMemory(const Renderer *renderer, const void *data, size_t dataSize)
{
    bool result = false;

    if (!m_texture)
    {
        m_texture = Texture::create();
        if (m_texture->loadFromMemory(renderer, data, dataSize))
        {
            result = true;
        }
    }

    return result;
}

bool SpriteComponent::loadFromLayer(const Renderer *renderer, const TmxMap *map, const char *layerName)
{
    bool result = false;

    if (!m_texture)
    {
        m_texture = Texture::create();
        if (m_texture->loadFromLayer(renderer, map, layerName))
        {
            result = true;
        }
    }

    return result;
}

bool SpriteComponent::loadFromObjectGroup(const Renderer *renderer, const TmxMap *map, const char *objectGroupName)
{
    bool result = false;

    if (!m_texture)
    {
        m_texture = Texture::create();
        if (m_texture->loadFromObjectGroup(renderer, map, objectGroupName))
        {
            result = true;
        }
    }

    return result;
}

bool SpriteComponent::loadFromColor(const Renderer *renderer, uint width, uint height, Color color)
{
    if (!m_texture)
    {
        m_texture = Texture::create();
        if (m_texture->loadFromColor(renderer, width, height, color))
        {
            return true;
        }
    }

    return false;
}

float SpriteComponent::getWidth() const
{
    return m_texture ? static_cast<float>(m_texture->getWidth()) : -1.0f;
}

float SpriteComponent::getHeight() const
{
    return m_texture ? static_cast<float>(m_texture->getHeight()) : -1.0f;
}

const Texture* SpriteComponent::getTexture() const
{
    return m_texture;
}
