//
// spriteComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 02/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SPRITE_COMPONENT_2_H__
#define __SPRITE_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/render/renderer/renderer2.hpp"
#include "core/render/texture/texture2.hpp"

namespace Jackbengine {

class SpriteComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(SpriteComponent2)

public:
    SpriteComponent2(const Renderer2& renderer, const std::string& file);
    SpriteComponent2(const Renderer2& renderer, const void *data, size_t dataSize);
    SpriteComponent2(const Renderer2& renderer, int width, int height, Color color);
    SpriteComponent2(const Renderer2& renderer, const TmxMap& map, const TmxLayer& layer,
                     const void *tilesetImageData, size_t tilesetImageDataSize);
    SpriteComponent2(const Renderer2& renderer, const TmxMap& map, const TmxObjectGroup& objectGroup,
                     const void *tilesetImageData, size_t tilesetImageDataSize);

    ~SpriteComponent2() override = default;

    const Texture2& texture() const;

private:
    Texture2 m_texture;
};

} // namespace Jackbengine

#endif // __SPRITE_COMPONENT_2_H__
