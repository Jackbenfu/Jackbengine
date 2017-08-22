//
// debugProfileSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_PROFILE_SYSTEM_2_H__
#define __DEBUG_PROFILE_SYSTEM_2_H__

#include <core/math/vector2d.hpp>
#include "system/system2.hpp"
#include "core/render/renderer/renderer2.hpp"
#include "core/time/timer2.hpp"
#include "component/view/textComponent2.hpp"

namespace Jackbengine {

class DebugProfileSystem2 : public System2
{
    DISALLOW_COPY_AND_MOVE(DebugProfileSystem2)

public:
    DebugProfileSystem2(Renderer2& renderer, Timer2& timer);
    ~DebugProfileSystem2() override = default;

    void setForeground(Color color);

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const int FontSize = {9};
    const std::string InvalidFpsText = "--";
    const std::string FpsSuffix = "fps";
    const Vec2i FpsPosition {4, 3};

    Renderer2& m_renderer;
    Timer2& m_timer;

    Font2 m_font;
    TextComponent2 m_fps;
};

} // namespace Jackbengine

#endif // __DEBUG_PROFILE_SYSTEM_2_H__
