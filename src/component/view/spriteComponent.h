//
// spriteComponent.h
// jackbengine
//
// Created by Damien Bendejacq on 25/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "component/component.h"
#include "core/render/renderer.h"
#include "core/render/texture.h"

NS_BEGIN_JKB

class SpriteComponent :
    public Component,
    public TypedObject<SpriteComponent>
{
public:
    SpriteComponent();
    ~SpriteComponent();

    bool loadFromFile(const Renderer *renderer, const char *file);

    bool loadFromMemory(const Renderer *renderer, const void *data, size_t dataSize);

    bool loadFromLayer(
        const Renderer *renderer, const TmxMap *map, const char *layerName,
        const void *tilesetImageData = nullptr, size_t tilesetImageDataSize = 0);

    bool loadFromObjectGroup(
        const Renderer *renderer, const TmxMap *map, const char *objectGroupName,
        const void *tilesetImageData = nullptr, size_t tilesetImageDataSize = 0);

    bool loadFromColor(const Renderer *renderer, uint width, uint height, Color color);

    bool loadFromTexture(const Renderer *renderer, Texture *texture);

    float getWidth() const;
    float getHeight() const;

    const Texture* getTexture() const;

private:
    Texture *m_texture = nullptr;
};

NS_END_JKB

#endif // __SPRITE_COMPONENT_H__
