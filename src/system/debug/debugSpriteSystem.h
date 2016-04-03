//
//  debugSpriteSystem.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 24/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_SPRITE_SYSTEM_H__
#define __DEBUG_SPRITE_SYSTEM_H__

#include "system/system.h"
#include "core/render/renderer.h"

NS_BEGIN_JKB

class DebugSpriteSystem :
    public System,
    public TypedObject<DebugSpriteSystem>
{
public:
    DebugSpriteSystem();
    ~DebugSpriteSystem();

    void update(float delta) override;

    void setRenderer(Renderer *renderer);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
};

NS_END_JKB

#endif // __DEBUG_SPRITE_SYSTEM_H__
