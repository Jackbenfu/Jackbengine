//
// texture2.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_2_IMPL_H__
#define __TEXTURE_2_IMPL_H__

#include "texture2.hpp"
#include "platform.hpp"
#include "core/sdl/surface/sdlSurface.hpp"

namespace Jackbengine {

class Texture2::Impl
{
public:
    Impl(const Renderer2& renderer, const std::string& file);
    Impl(const Renderer2& renderer, const void *data, size_t dataSize);
    Impl(const Renderer2& renderer, int width, int height, Color color);
    Impl(const Renderer2& renderer, const TmxMap& map, const TmxLayer& layer,
         const void *tilesetImageData, size_t tilesetImageDataSize);
    Impl(const Renderer2& renderer, const TmxMap& map, const TmxObjectGroup& objectGroup,
         const void *tilesetImageData, size_t tilesetImageDataSize);
    Impl(const Renderer2& renderer, const Font2& font, const std::string& text, Color foreground);

    ~Impl();

    int getWidth() const;
    int getHeight() const;

    SDL_Texture* getInternalObject() const;

private:
    void loadTextureFromSurface(const Renderer2& renderer, const SdlSurface& surface);

    SDL_Texture *m_texture {nullptr};
    SDL_Rect m_rect {0, 0, 0, 0};
};

} // namespace Jackbengine

#endif // __TEXTURE_2_IMPL_H__
