//
// spriteRenderSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 02/05/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __SPRITE_RENDER_SYSTEM_H__
#define __SPRITE_RENDER_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer.hpp"

namespace Jackbengine {

class SpriteRenderSystem : public System
{
public:
    SpriteRenderSystem();
    ~SpriteRenderSystem() override;

    void update(float delta) override;

    void setRenderer(Renderer *renderer);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
};

} // namespace Jackbengine

#endif // __SPRITE_RENDER_SYSTEM_H__
