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
    : m_renderer {renderer}
{
    // Nothing
}

void DebugTextSystem2::frame(float delta)
{
    UNUSED(delta);

    for (auto& entity : m_entities)
    {
        auto components = entity.second;

        auto& container = components->get<ContainerComponent2>();

        Vec2i position {container.getX(), container.getY()};
        float w = container.getWidth();
        float h = container.getHeight();

        auto x1 = position.x;
        auto x2 = position.x + w;
        auto y1 = position.y;
        auto y2 = position.y + h;

        m_renderer.renderLine(x1, y1, x2, y1, Color_Red);
        m_renderer.renderLine(x2, y1, x2, y2, Color_Red);
        m_renderer.renderLine(x2, y2, x1, y2, Color_Red);
        m_renderer.renderLine(x1, y2, x1, y1, Color_Red);
    }
}

bool DebugTextSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<TextComponent2>()
        && components.any<ContainerComponent2>();
}
