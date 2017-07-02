//
// textRenderSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 14/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_RENDER_SYSTEM_H__
#define __TEXT_RENDER_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer.hpp"

#include "component/layout/containerComponent.hpp"
#include "component/view/textComponent.hpp"
#include "component/body/transformComponent.hpp"

namespace Jackbengine {

class TextRenderSystem : public System
{
public:
    TextRenderSystem();
    ~TextRenderSystem() override;

    void update(float delta) override;

    void setRenderer(Renderer *renderer);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
};

} // namespace Jackbengine

#endif // __TEXT_RENDER_SYSTEM_H__
