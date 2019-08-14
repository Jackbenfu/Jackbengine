//
// texture.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "texture.h"
#include "core/render/renderer/renderer.h"

namespace Jackbengine {

Texture::Texture(const Renderer &renderer, const std::string &file)
{
    const auto sdlSurface = std::make_unique<SdlSurface>(file);

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::Texture(const Renderer &renderer, const void *data, size_t dataSize)
{
    const auto sdlRwops = std::make_unique<SdlRwops>(data, dataSize);
    const auto sdlSurface = std::make_unique<SdlSurface>(*sdlRwops);

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::Texture(const Renderer &renderer, int width, int height, Color color)
{
    const auto sdlSurface = std::make_unique<SdlSurface>(width, height, 32);
    const auto sdlSurfaceObject = (SDL_Surface *) sdlSurface->internalObject();

    const auto rgbUint = SDL_MapRGB(sdlSurfaceObject->format, color.r, color.g, color.b);
    if (SDL_FillRect(sdlSurfaceObject, nullptr, rgbUint) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::Texture(const Renderer &renderer, const Font &font, const std::string &text, Color foreground)
{
    const auto sdlSurface = std::make_unique<SdlSurface>(font, text, foreground);

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::~Texture()
{
    SDL_DestroyTexture(m_texture);
}

int Texture::width() const
{
    return m_rect.w;
}

int Texture::height() const
{
    return m_rect.h;
}

void Texture::loadTextureFromSurface(const Renderer &renderer, const SdlSurface &surface)
{
    const auto sdlRenderer = renderer.m_renderer;

    m_texture = SDL_CreateTextureFromSurface(sdlRenderer, (SDL_Surface *) surface.internalObject());
    if (nullptr == m_texture)
    {
        throw std::runtime_error(SDL_GetError());
    }

    if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

}
