//
// textRenderSystem.h
// jackbengine
//
// Created by Damien Bendejacq on 14/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_RENDER_SYSTEM_H__
#define __TEXT_RENDER_SYSTEM_H__

#include "system/system.h"
#include "core/render/renderer.h"

#include "component/layout/containerComponent.h"
#include "component/view/textComponent.h"
#include "component/body/transformComponent.h"

NS_BEGIN_JKB

class TextRenderSystem :
    public System,
    public TypedObject<TextRenderSystem>
{
public:
    TextRenderSystem();
    ~TextRenderSystem();

    void update(float delta) override;

    void setRenderer(Renderer *renderer);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
};

NS_END_JKB

#endif // __TEXT_RENDER_SYSTEM_H__
