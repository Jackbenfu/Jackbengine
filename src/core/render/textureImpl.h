//
//  textureImpl.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_IMPL_H__
#define __TEXTURE_IMPL_H__

#include "texture.h"
#include "rendererImpl.h"

NS_BEGIN_JKB

class TextureImpl : public Texture
{
    friend class Texture;

public:
    ~TextureImpl();

    bool loadFromFile(const Renderer *renderer, const char *file) override;
    bool loadFromLayer(const Renderer *renderer, const TmxMap *map, const char *layerName) override;
    bool loadFromObjectGroup(const Renderer *renderer, const TmxMap *map, const char *objectGroupName) override;
    bool loadFromColor(const Renderer *renderer, int width, int height, Color color) override;
    bool loadFromFont(const Renderer *renderer, const Font *font, Color foreground, const string& text) override;

    int getWidth() const override;
    int getHeight() const override;

    SDL_Texture* getRawTexture() const;

private:
    TextureImpl();

    bool loadTextureFromSurface(const Renderer *renderer, SDL_Surface *surface);

    SDL_Texture *m_texture = nullptr;
    SDL_Rect m_rect;
    bool m_isInitialized = false;
};

NS_END_JKB

#endif // __TEXTURE_IMPL_H__