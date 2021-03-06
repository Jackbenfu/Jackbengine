//
// textDebugSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "textDebugSystem.hpp"
#include "component/layout/containerComponent.hpp"
#include "component/view/textComponent.hpp"

namespace Jackbengine {

TextDebugSystem::TextDebugSystem(const Renderer& renderer)
    : TextDebugSystem {renderer, Color(255, 0, 0)}
{
}

TextDebugSystem::TextDebugSystem(const Renderer& renderer, Color color)
    : m_renderer {renderer},
      m_color {color}
{
}

int TextDebugSystem::order() const
{
    return (int) SystemOrder::TextDebug;
}

void TextDebugSystem::frame(float)
{
    for (const auto&[entity, components] : entities())
    {
        const auto container = components->get<ContainerComponent>();

        const Vec2f position {container->x(), container->y()};
        const float w = container->width();
        const float h = container->height();

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

bool TextDebugSystem::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<TextComponent>()
           && components.any<ContainerComponent>();
}

}
