//
//  spriteRenderSystem.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 02/05/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __SPRITE_RENDER_SYSTEM_H__
#define __SPRITE_RENDER_SYSTEM_H__

#include "system/system.h"
#include "core/render/renderer.h"

NS_BEGIN_JKB

class SpriteRenderSystem :
    public System,
    public TypedObject<SpriteRenderSystem>
{
public:
    SpriteRenderSystem();
    ~SpriteRenderSystem();

    void update(float delta) override;

    void setRenderer(Renderer *renderer);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
};

NS_END_JKB

#endif // __SPRITE_RENDER_SYSTEM_H__
