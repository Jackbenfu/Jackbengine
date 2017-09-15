//
// texture2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXTURE_2_H__
#define __TEXTURE_2_H__

#include <memory>
#include "core/render/color32.hpp"
#include "core/render/font/font2.hpp"
#include "core/tmx/tmxMap.hpp"

namespace Jackbengine {

class Renderer2;

class Texture2
{
    friend class Renderer2;

    DISALLOW_COPY_AND_MOVE(Texture2)

public:
    Texture2(const Renderer2& renderer, const std::string& file);
    Texture2(const Renderer2& renderer, const void *data, size_t dataSize);
    Texture2(const Renderer2& renderer, int width, int height, Color32 color);
    Texture2(const Renderer2& renderer, const TmxMap& map, const TmxLayer& layer,
             const void *tilesetImageData, size_t tilesetImageDataSize);
    Texture2(const Renderer2& renderer, const TmxMap& map, const TmxObjectGroup& objectGroup,
             const void *tilesetImageData, size_t tilesetImageDataSize);
    Texture2(const Renderer2& renderer, const Font2& font, const std::string& text, Color32 foreground);

    ~Texture2();

    int width() const;
    int height() const;

private:
    void* internalObject() const;

    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __TEXTURE_2_H__
