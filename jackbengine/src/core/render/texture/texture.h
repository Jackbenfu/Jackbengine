//
// texture.h
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "core/sdl/sdl.h"
#include "core/sdl/surface/sdlSurface.h"
#include "core/render/color.h"
#include "core/render/font/font.h"

namespace Jackbengine {

class Renderer;

class Texture
{
    friend class Renderer;

public:
    Texture(const Renderer &renderer, const std::string &file);
    Texture(const Renderer &renderer, const void *data, size_t dataSize);
    Texture(const Renderer &renderer, int width, int height, Color color);
    Texture(const Renderer &renderer, const Font &font, const std::string &text, Color foreground);

    ~Texture();

    int width() const;
    int height() const;

private:
    void loadTextureFromSurface(const Renderer &renderer, const SdlSurface &surface);

    SDL_Texture *m_texture {nullptr};
    SDL_Rect m_rect {0, 0, 0, 0};
};

}

#endif // __TEXTURE_H__
