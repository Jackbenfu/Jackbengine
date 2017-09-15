//
// debugProfileSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include <sstream>
#include "debugProfileSystem2.hpp"
#include "core/resource/importResource.hpp"

using namespace Jackbengine;

IMPORT_BINARY_RESOURCE(default_font)

DebugProfileSystem2::DebugProfileSystem2(Renderer2& renderer, Timer2& timer)
    : m_renderer {renderer},
      m_timer {timer},
      m_font {default_font, default_font_size, FontSize},
      m_fps {m_renderer, m_font, InvalidFpsText}
{
    // Nothing
}

DebugProfileSystem2::DebugProfileSystem2(Renderer2& renderer, Timer2& timer, Color32 foreground)
    : m_renderer {renderer},
      m_timer {timer},
      m_font {default_font, default_font_size, FontSize},
      m_fps {m_renderer, m_font, InvalidFpsText, foreground}
{
    // Nothing
}

bool DebugProfileSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    UNUSED(components);

    return false;
}

void DebugProfileSystem2::frame(float delta)
{
    UNUSED(delta);

    const auto fps = m_timer.fps();

    std::stringstream sstream;
    if (fps <= 0)
    {
        sstream << InvalidFpsText;
    }
    else
    {
        sstream << fps << FpsSuffix;
    }

    m_fps.setText(sstream.str());
    m_renderer.renderTexture(FpsPosition.x, FpsPosition.y, m_fps.texture());
}
