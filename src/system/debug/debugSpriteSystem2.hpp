//
// debugSpriteSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_SPRITE_SYSTEM_2_H__
#define __DEBUG_SPRITE_SYSTEM_2_H__

#include "system/system2.hpp"
#include "core/render/renderer/renderer2.hpp"

namespace Jackbengine {

class DebugSpriteSystem2 : public System2
{
    DISALLOW_COPY_AND_MOVE(DebugSpriteSystem2)

public:
    explicit DebugSpriteSystem2(Renderer2& renderer);
    ~DebugSpriteSystem2() override = default;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    Renderer2& m_renderer;
    const Color32 m_color;
};

} // namespace Jackbengine

#endif // __DEBUG_SPRITE_SYSTEM_2_H__
