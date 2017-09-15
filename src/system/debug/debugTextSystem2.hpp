//
// debugTextSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_TEXT_SYSTEM_2_H__
#define __DEBUG_TEXT_SYSTEM_2_H__

#include "system/system2.hpp"
#include "core/render/renderer/renderer2.hpp"

namespace Jackbengine {

class DebugTextSystem2 : public  System2
{
    DISALLOW_COPY_AND_MOVE(DebugTextSystem2)

public:
    explicit DebugTextSystem2(Renderer2& renderer);
    DebugTextSystem2(Renderer2& renderer, Color32 color);
    ~DebugTextSystem2() override = default;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    Renderer2& m_renderer;
    Color32 m_color;
};

} // namespace Jackbengine

#endif // __DEBUG_TEXT_SYSTEM_2_H__
