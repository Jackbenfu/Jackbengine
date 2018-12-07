//
// spriteRenderSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SPRITE_RENDER_SYSTEM_H__
#define __SPRITE_RENDER_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer/renderer.hpp"

namespace Jackbengine {

class SpriteRenderSystem final : public System
{
DISALLOW_COPY_AND_MOVE(SpriteRenderSystem)

public:
    SpriteRenderSystem() = delete;
    explicit SpriteRenderSystem(const Renderer& renderer);
    ~SpriteRenderSystem() override = default;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    void sortByZIndex();

    const Renderer& m_renderer;
};

}

#endif // __SPRITE_RENDER_SYSTEM_H__
