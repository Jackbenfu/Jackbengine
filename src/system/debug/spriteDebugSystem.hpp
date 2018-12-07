//
// spriteDebugSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SPRITE_DEBUG_SYSTEM_H__
#define __SPRITE_DEBUG_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer/renderer.hpp"

namespace Jackbengine {

class SpriteDebugSystem final : public System
{
DISALLOW_COPY_AND_MOVE(SpriteDebugSystem)

public:
    SpriteDebugSystem() = delete;
    explicit SpriteDebugSystem(const Renderer& renderer);
    ~SpriteDebugSystem() override = default;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const Renderer& m_renderer;
    const Color m_color;
};

}

#endif // __SPRITE_DEBUG_SYSTEM_H__
