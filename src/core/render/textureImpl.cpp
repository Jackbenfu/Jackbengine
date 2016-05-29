//
//  textureImpl.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "textureImpl.h"
#include "fontImpl.h"

TextureImpl::TextureImpl()
{
    m_rect.x = 0;
    m_rect.y = 0;
    m_rect.w = 0;
    m_rect.h = 0;
}

TextureImpl::~TextureImpl()
{
    SDL_DestroyTexture(m_texture);
}

bool TextureImpl::loadFromFile(const Renderer *renderer, const char *file)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    SDL_Surface *surface = IMG_Load(file);

    m_isInitialized = loadTextureFromSurface(renderer, surface);

    return m_isInitialized;
}

bool TextureImpl::loadFromMemory(const Renderer *renderer, const void *data, size_t dataSize)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    auto *rWops = SDL_RWFromConstMem(data, dataSize);
    if (!rWops)
    {
        LOG_ERROR("%s", SDL_GetError())
        return false;
    }

    SDL_Surface *surface = IMG_Load_RW(rWops, 1);

    m_isInitialized = loadTextureFromSurface(renderer, surface);

    return m_isInitialized;
}

bool TextureImpl::loadFromLayer(
    const Renderer *renderer, const TmxMap *map, const char *layerName,
    const void *tilesetImageData, size_t tilesetImageDataSize)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    const TmxLayer *layer = map->getLayer(layerName);
    if (!layer)
    {
        LOG_ERROR("Layer [%s] not found in map", layerName)
        return false;
    }

    const TmxTileset *tileset = map->getTileset();

    SDL_Surface *tilesetSurface;
    if (nullptr == tilesetImageData)
    {
        tilesetSurface = IMG_Load(tileset->getImage()->getSource());
    }
    else
    {
        auto *rWops = SDL_RWFromConstMem(tilesetImageData, (int)tilesetImageDataSize);
        if (!rWops)
        {
            LOG_ERROR("%s", SDL_GetError())
            return false;
        }

        tilesetSurface = IMG_Load_RW(rWops, 1);
    }

    if (!tilesetSurface)
    {
        LOG_ERROR("%s", IMG_GetError())
        return false;
    }

    int layerWidth = layer->getWidth();
    int layerHeight = layer->getHeight();

    int tileWidth = tileset->getTileWidth();
    int tileHeight = tileset->getTileHeight();

    int surfaceWidth = layerWidth * tileset->getTileWidth();
    int surfaceHeight = layerHeight * tileset->getTileHeight();

    SDL_Surface *surface = SDL_CreateRGBSurface(
        SDL_SWSURFACE, surfaceWidth, surfaceHeight, 32, 0, 0, 0, 0
    );

    if (!surface)
    {
        LOG_ERROR("%s", IMG_GetError())

        SDL_FreeSurface(tilesetSurface);
        return false;
    }

    for (int row = 0; row < layerHeight; ++row)
    {
        for (int col = 0; col < layerWidth; ++col)
        {
            int tileId = layer->getTileId(col, row);

            if (0 >= tileId)
            {
                continue;
            }

            // Zero based gid on the tileset
            --tileId;

            int tilesetCol = tileId % (tilesetSurface->w / tileWidth);
            int tilesetRow = tileId / (tilesetSurface->h / tileHeight);

            SDL_Rect srcRect;
            srcRect.x = tilesetCol * tileWidth;
            srcRect.y = tilesetRow * tileHeight;
            srcRect.w = tileWidth;
            srcRect.h = tileHeight;

            SDL_Rect dstRect;
            dstRect.x = col * tileWidth;
            dstRect.y = row * tileHeight;
            dstRect.w = tileWidth;
            dstRect.h = tileHeight;

            SDL_BlitSurface(tilesetSurface, &srcRect, surface, &dstRect);
        }
    }

    SDL_FreeSurface(tilesetSurface);

    m_isInitialized = loadTextureFromSurface(renderer, surface);

    return m_isInitialized;
}

bool TextureImpl::loadFromObjectGroup(
    const Renderer *renderer, const TmxMap *map, const char *objectGroupName,
    const void *tilesetImageData, size_t tilesetImageDataSize)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    const TmxObjectGroup *objectGroup = map->getObjectGroup(objectGroupName);
    if (!objectGroup)
    {
        LOG_ERROR("Object group [%s] not found in map", objectGroupName)
        return false;
    }

    int objectCount = objectGroup->getObjectCount();
    if (0 < objectCount)
    {
        int minX = objectGroup->getObject(0)->getX();
        int minY = objectGroup->getObject(0)->getY();
        int maxX = minX;
        int maxY = minY;
        for (int i = 0; i < objectCount; ++i)
        {
            const TmxObject *object = objectGroup->getObject(i);
            if (0 < object->getGid())
            {
                int x = object->getX();
                int y = object->getY();

                minX = x < minX ? x : minX;
                minY = y < minY ? y : minY;
                maxX = x > maxX ? x : maxX;
                maxY = y > maxY ? y : maxY;
            }
        }

        const TmxTileset *tileset = map->getTileset();

        SDL_Surface *tilesetSurface;
        if (nullptr == tilesetImageData)
        {
            tilesetSurface = IMG_Load(tileset->getImage()->getSource());
        }
        else
        {
            auto *rWops = SDL_RWFromConstMem(tilesetImageData, (int)tilesetImageDataSize);
            if (!rWops)
            {
                LOG_ERROR("%s", SDL_GetError())
                return false;
            }

            tilesetSurface = IMG_Load_RW(rWops, 1);
        }
        if (!tilesetSurface)
        {
            LOG_ERROR("%s", IMG_GetError())
            return false;
        }

        int tileWidth = tileset->getTileWidth();
        int tileHeight = tileset->getTileHeight();

        int surfaceWidth = tileWidth + maxX - minX;
        int surfaceHeight = tileHeight + maxY - minY;

        SDL_Surface *surface = SDL_CreateRGBSurface(
            SDL_SWSURFACE, surfaceWidth, surfaceHeight, 32, 0, 0, 0, 0
        );

        if (!surface)
        {
            LOG_ERROR("%s", IMG_GetError())

            SDL_FreeSurface(tilesetSurface);
            return false;
        }

        for (int i = 0; i < objectCount; ++i)
        {
            const TmxObject *object = objectGroup->getObject(i);
            int tileId = object->getGid();
            if (0 < tileId)
            {
                --tileId;

                int x = object->getX() - minX;
                int y = object->getY() - minY;

                int tilesetCol = tileId % (tilesetSurface->w / tileWidth);
                int tilesetRow = tileId / (tilesetSurface->h / tileHeight);

                SDL_Rect srcRect;
                srcRect.x = tilesetCol * tileWidth;
                srcRect.y = tilesetRow * tileHeight;
                srcRect.w = tileWidth;
                srcRect.h = tileHeight;

                SDL_Rect dstRect;
                dstRect.x = x;
                dstRect.y = y;
                dstRect.w = tileWidth;
                dstRect.h = tileHeight;

                SDL_BlitSurface(tilesetSurface, &srcRect, surface, &dstRect);
            }
        }

        SDL_FreeSurface(tilesetSurface);

        m_isInitialized = loadTextureFromSurface(renderer, surface);

        return m_isInitialized;
    }

    return false;
}

bool TextureImpl::loadFromColor(const Renderer *renderer, int width, int height, Color color)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    SDL_Surface *surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    if (!surface)
    {
        LOG_ERROR("%s", SDL_GetError())
        return false;
    }

    if (SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b)) < 0)
    {
        LOG_ERROR("%s", SDL_GetError())

        SDL_FreeSurface(surface);
        return false;
    }

    m_isInitialized = loadTextureFromSurface(renderer, surface);

    return m_isInitialized;
}

bool TextureImpl::loadFromFont(
    const Renderer *renderer, const Font *font, Color foreground, const string& text)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    FontImpl *fontImpl = (FontImpl*)font;

    if (fontImpl)
    {
        SDL_Color sdlForeground;
        sdlForeground.r = foreground.r;
        sdlForeground.g = foreground.g;
        sdlForeground.b = foreground.b;
        sdlForeground.a = foreground.a;

        SDL_Surface *surface;
        surface = TTF_RenderUTF8_Solid(fontImpl->getRawFont(), text.c_str(), sdlForeground);
        if (!surface)
        {
            LOG_ERROR("%s", SDL_GetError())
            return false;
        }

        m_isInitialized = loadTextureFromSurface(renderer, surface);

        return m_isInitialized;
    }

    return false;
}

int TextureImpl::getWidth() const
{
    return m_rect.w;
}

int TextureImpl::getHeight() const
{
    return m_rect.h;
}

SDL_Texture* TextureImpl::getRawTexture() const
{
    return m_texture;
}

bool TextureImpl::loadTextureFromSurface(const Renderer *renderer, SDL_Surface *surface)
{
    RendererImpl *rendererImpl = (RendererImpl*)renderer;
    if (!rendererImpl)
    {
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(rendererImpl->getRawRenderer(), surface);
    if (!m_texture)
    {
        LOG_ERROR("%s", SDL_GetError())
        return false;
    }

    if (0 > SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h))
    {
        LOG_ERROR("%s", SDL_GetError())
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}

bool TextureImpl::errorAlreadyLoaded() const
{
    LOG_ERROR("Texture instance already loaded")
    return false;
}
