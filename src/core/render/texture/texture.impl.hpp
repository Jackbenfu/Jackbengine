//
// texture.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_IMPL_H__
#define __TEXTURE_IMPL_H__

#include "core/sdl/sdl.hpp"
#include "texture.hpp"
#include "core/sdl/surface/sdlSurface.hpp"

namespace Jackbengine {

class Texture::Impl
{
public:
    Impl(const Renderer& renderer, const std::string& file);
    Impl(const Renderer& renderer, const void *data, size_t dataSize);
    Impl(const Renderer& renderer, int width, int height, Color32 color);
    Impl(const Renderer& renderer, const Font& font, const std::string& text, Color32 foreground);

    ~Impl();

    int width() const;
    int height() const;

    SDL_Texture *internalObject() const;

private:
    void loadTextureFromSurface(const Renderer& renderer, const SdlSurface& surface);

    SDL_Texture *m_texture {nullptr};
    SDL_Rect m_rect {0, 0, 0, 0};
};

}

#endif // __TEXTURE_IMPL_H__
