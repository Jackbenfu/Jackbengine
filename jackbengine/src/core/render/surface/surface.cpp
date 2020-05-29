//
// surface.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
//

#include <stdexcept>
#include <core/render/window/window.h>

#include "surface.h"
#include "core/sdl/sdlinc.h"

namespace Jackbengine::details {

Surface::Surface(const std::string& file)
{
    m_surface = IMG_Load(file.c_str());
    if (nullptr == m_surface)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

Surface::Surface(const RWops& rwops)
{
    m_surface = IMG_Load_RW(rwops.nativeObject(), 0);
    if (nullptr == m_surface)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

Surface::Surface(const Window& window)
{
    m_mustBeFreed = false;
    m_surface = SDL_GetWindowSurface(window.nativeWindow());
}

Surface::Surface(int width, int height, int depth)
{
    m_surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, depth, 0, 0, 0, 0);
    if (nullptr == m_surface)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Surface::Surface(const Font& font, const std::string& text, Color foreground)
{
    const auto sdlFont = font.m_font;

    SDL_Color sdlForeground {foreground.r, foreground.g, foreground.b, foreground.a};

    m_surface = TTF_RenderUTF8_Solid(sdlFont, text.c_str(), sdlForeground);
    if (nullptr == m_surface)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

Surface::~Surface()
{
    if (m_mustBeFreed)
    {
        SDL_FreeSurface((SDL_Surface*) m_surface);
    }
}

SDL_Surface* Surface::nativeObject() const
{
    return m_surface;
}

}
