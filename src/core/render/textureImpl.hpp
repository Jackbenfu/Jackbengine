//
// textureImpl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_IMPL_H__
#define __TEXTURE_IMPL_H__

#include "texture.hpp"
#include "rendererImpl.hpp"

namespace Jackbengine {

class TextureImpl : public Texture
{
    friend class Texture;

public:
    ~TextureImpl() override;

    bool loadFromFile(const Renderer *renderer, const char *file) override;

    bool loadFromMemory(const Renderer *renderer, const void *data, size_t dataSize) override;

    bool loadFromLayer(
        const Renderer *renderer, const TmxMap *map, const char *layerName,
        const void *tilesetImageData = nullptr, size_t tilesetImageDataSize = 0) override;

    bool loadFromObjectGroup(
        const Renderer *renderer, const TmxMap *map, const char *objectGroupName,
        const void *tilesetImageData = nullptr, size_t tilesetImageDataSize = 0) override;

    bool loadFromColor(const Renderer *renderer, int width, int height, Color32 color) override;

    bool loadFromFont(
        const Renderer *renderer, const Font *font, Color32 foreground, const std::string& text) override;

    int getWidth() const override;
    int getHeight() const override;

    SDL_Texture* getRawTexture() const;

private:
    TextureImpl();

    bool loadTextureFromSurface(const Renderer *renderer, SDL_Surface *surface);

    SDL_Texture *m_texture = nullptr;
    SDL_Rect m_rect;
    bool m_isInitialized {false};

    bool errorAlreadyLoaded() const;
};

} // namespace Jackbengine

#endif // __TEXTURE_IMPL_H__
