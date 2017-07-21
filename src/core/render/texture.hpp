//
// texture.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "core/math/vector2d.hpp"
#include "core/tmx/tmxMap.hpp"
#include "renderer.hpp"
#include "font.hpp"

namespace Jackbengine {

class Texture
{
public:
    virtual ~Texture();

    virtual bool loadFromFile(const Renderer *renderer, const char *file) = 0;

    virtual bool loadFromMemory(const Renderer *renderer, const void *data, size_t dataSize) = 0;

    virtual bool loadFromLayer(
        const Renderer *renderer, const TmxMap *map, const char *layerName,
        const void *tilesetImageData = nullptr, size_t tilesetImageDataSize = 0) = 0;

    virtual bool loadFromObjectGroup(
        const Renderer *renderer, const TmxMap *map, const char *objectGroupName,
        const void *tilesetImageData = nullptr, size_t tilesetImageDataSize = 0) = 0;

    virtual bool loadFromColor(const Renderer *renderer, int width, int height, Color color) = 0;

    virtual bool loadFromFont(
        const Renderer *renderer, const Font *font, Color foreground, const std::string& text) = 0;

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    static Texture* create();

protected:
    Texture();
};

} // namespace Jackbengine

#endif // __TEXTURE_H__