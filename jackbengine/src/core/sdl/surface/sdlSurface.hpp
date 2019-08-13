//
// sdlSurface.hpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SDL_SURFACE_H__
#define __SDL_SURFACE_H__

#include <string>

#include "core/render/font/font.hpp"
#include "core/render/color.hpp"
#include "core/sdl/io/sdlRwops.hpp"

namespace Jackbengine {

class SdlSurface
{
public:
    explicit SdlSurface(const std::string &file);
    explicit SdlSurface(const SdlRwops &rwops);
    SdlSurface(int width, int height, int depth);
    SdlSurface(const Font &font, const std::string &text, Color foreground);
    ~SdlSurface();

    void *internalObject() const;

private:
    void *m_surface {nullptr};
};

}

#endif // __SDL_SURFACE_H__
