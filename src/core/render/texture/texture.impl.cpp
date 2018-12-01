//
// texture.impl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "texture.impl.hpp"
#include "core/render/renderer/renderer.hpp"

namespace Jackbengine {

Texture::Impl::Impl(const Renderer& renderer, const std::string& file)
{
    const auto sdlSurface = std::make_unique<SdlSurface>(file);

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::Impl::Impl(const Renderer& renderer, const void *data, size_t dataSize)
{
    const auto sdlRwops = std::make_unique<SdlRwops>(data, dataSize);
    const auto sdlSurface = std::make_unique<SdlSurface>(*sdlRwops);

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::Impl::Impl(const Renderer& renderer, int width, int height, Color32 color)
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

Texture::Impl::Impl(const Renderer& renderer, const Font& font, const std::string& text, Color32 foreground)
{
    const auto sdlSurface = std::make_unique<SdlSurface>(font, text, foreground);

    loadTextureFromSurface(renderer, *sdlSurface);
}

Texture::Impl::~Impl()
{
    SDL_DestroyTexture(m_texture);
}

int Texture::Impl::width() const
{
    return m_rect.w;
}

int Texture::Impl::height() const
{
    return m_rect.h;
}

SDL_Texture *Texture::Impl::internalObject() const
{
    return m_texture;
}

void Texture::Impl::loadTextureFromSurface(const Renderer& renderer, const SdlSurface& surface)
{
    const auto sdlRenderer = static_cast<SDL_Renderer *>(renderer.internalObject());

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
