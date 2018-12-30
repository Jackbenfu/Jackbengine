//
// sdlSurface.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "core/sdl/sdl.hpp"
#include "sdlSurface.hpp"

namespace Jackbengine {

SdlSurface::SdlSurface(const std::string& file)
{
    m_surface = IMG_Load(file.c_str());
    if (nullptr == m_surface)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

SdlSurface::SdlSurface(const SdlRwops& rwops)
{
    m_surface = IMG_Load_RW((SDL_RWops *) rwops.internalObject(), 0);
    if (nullptr == m_surface)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

SdlSurface::SdlSurface(int width, int height, int depth)
{
    m_surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, depth, 0, 0, 0, 0);
    if (nullptr == m_surface)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

SdlSurface::SdlSurface(const Font& font, const std::string& text, Color foreground)
{
    const auto sdlFont = font.m_font;

    SDL_Color sdlForeground {foreground.r, foreground.g, foreground.b, foreground.a};

    m_surface = TTF_RenderUTF8_Solid(sdlFont, text.c_str(), sdlForeground);
    if (nullptr == m_surface)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

SdlSurface::~SdlSurface()
{
    SDL_FreeSurface((SDL_Surface *) m_surface);
}

void *SdlSurface::internalObject() const
{
    return m_surface;
}

}
