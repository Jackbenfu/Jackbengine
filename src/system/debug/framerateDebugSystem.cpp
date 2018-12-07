//
// framerateDebugSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include <sstream>
#include "framerateDebugSystem.hpp"
#include "core/resource/importResource.hpp"

namespace Jackbengine {

IMPORT_BINARY_RESOURCE(default_font)

FramerateDebugSystem::FramerateDebugSystem(const Renderer& renderer, const Timer& timer)
    : m_renderer {renderer},
      m_timer {timer},
      m_fps {m_renderer, InvalidFpsText, TextLayout::LeftTop, Color(255, 255, 255), FontSize, default_font,
             default_font_size}
{
}

FramerateDebugSystem::FramerateDebugSystem(const Renderer& renderer, const Timer& timer, Color foreground)
    : m_renderer {renderer},
      m_timer {timer},
      m_fps {m_renderer, InvalidFpsText, TextLayout::LeftTop, foreground, FontSize, default_font, default_font_size}
{
}

int FramerateDebugSystem::order() const
{
    return (int) SystemOrder::FramerateDebug;
}

void FramerateDebugSystem::frame(float)
{
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

bool FramerateDebugSystem::hasRequiredComponents(ComponentCollection&) const
{
    return false;
}

}
