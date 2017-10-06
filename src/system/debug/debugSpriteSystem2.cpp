//
// debugSpriteSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "debugSpriteSystem2.hpp"
#include "component/body/shape/boxShapeComponent2.hpp"
#include "component/body/transformComponent2.hpp"

using namespace Jackbengine;

DebugSpriteSystem2::DebugSpriteSystem2(Renderer2& renderer)
    : m_renderer {renderer},
      m_color {Color32(255, 0, 0)}
{ }

void DebugSpriteSystem2::frame(float)
{
    for (const auto& entity : m_entities)
    {
        const auto components = entity.second;

        const auto& boxShape = components->get<BoxShapeComponent2>();
        const auto& transform = components->get<TransformComponent2>();

        const auto position = transform.position();
        const auto size = boxShape.size();

        const auto x1 = position.x;
        const auto x2 = position.x + size.x;
        const auto y1 = position.y;
        const auto y2 = position.y + size.y;

        m_renderer.renderLine(x1, y1, x2, y1, m_color);
        m_renderer.renderLine(x2, y1, x2, y2, m_color);
        m_renderer.renderLine(x2, y2, x1, y2, m_color);
        m_renderer.renderLine(x1, y2, x1, y1, m_color);
    }
}

bool DebugSpriteSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<BoxShapeComponent2>()
        && components.any<TransformComponent2>();
}
