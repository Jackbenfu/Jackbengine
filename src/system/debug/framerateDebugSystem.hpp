//
// framerateDebugSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __FRAMERATE_DEBUG_SYSTEM_H__
#define __FRAMERATE_DEBUG_SYSTEM_H__

#include <core/math/vector2d.hpp>
#include "system/system.hpp"
#include "core/render/renderer/renderer.hpp"
#include "core/time/timer.hpp"
#include "component/view/textComponent.hpp"

namespace Jackbengine {

class FramerateDebugSystem final : public System
{
DISALLOW_COPY_AND_MOVE(FramerateDebugSystem)

public:
    FramerateDebugSystem(const Renderer& renderer, const Timer& timer);
    FramerateDebugSystem(const Renderer& renderer, const Timer& timer, Color32 foreground);
    ~FramerateDebugSystem() override = default;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const int FontSize = {9};
    const std::string InvalidFpsText = "--";
    const std::string FpsSuffix = "fps";
    const Vec2i FpsPosition {4, 3};

    const Renderer& m_renderer;
    const Timer& m_timer;

    TextComponent m_fps;
};

}

#endif // __FRAMERATE_DEBUG_SYSTEM_H__
