//
// debugTextSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "debugTextSystem2.hpp"
#include "component/layout/containerComponent2.hpp"
#include "component/view/textComponent2.hpp"
#include "component/body/transformComponent2.hpp"

using namespace Jackbengine;

DebugTextSystem2::DebugTextSystem2(Renderer2& renderer)
    : DebugTextSystem2 {renderer, Color_Red}
{ }

DebugTextSystem2::DebugTextSystem2(Renderer2& renderer, Color32 color)
    : m_renderer {renderer},
      m_color {color}
{ }

void DebugTextSystem2::frame(float)
{
    for (const auto& entity : m_entities)
    {
        const auto components = entity.second;

        const auto& container = components->get<ContainerComponent2>();

        const Vec2i position {container.x(), container.y()};
        const float w = container.width();
        const float h = container.height();

        const auto x1 = position.x;
        const auto x2 = position.x + w;
        const auto y1 = position.y;
        const auto y2 = position.y + h;

        m_renderer.renderLine(x1, y1, x2, y1, m_color);
        m_renderer.renderLine(x2, y1, x2, y2, m_color);
        m_renderer.renderLine(x2, y2, x1, y2, m_color);
        m_renderer.renderLine(x1, y2, x1, y1, m_color);
    }
}

bool DebugTextSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<TextComponent2>()
        && components.any<ContainerComponent2>();
}
