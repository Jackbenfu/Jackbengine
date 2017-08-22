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
    : m_renderer {renderer}
{
    // Nothing
}

void DebugSpriteSystem2::frame(float delta)
{
    UNUSED(delta);

    for (auto& entity : m_entities)
    {
        auto components = entity.second;

        auto& boxShape = components->get<BoxShapeComponent2>();
        auto& transform = components->get<TransformComponent2>();

        auto position = transform.getPosition();
        auto size = boxShape.getSize();

        auto x1 = position.x;
        auto x2 = position.x + size.x;
        auto y1 = position.y;
        auto y2 = position.y + size.y;

        m_renderer.renderLine(x1, y1, x2, y1, Color_Red);
        m_renderer.renderLine(x2, y1, x2, y2, Color_Red);
        m_renderer.renderLine(x2, y2, x1, y2, Color_Red);
        m_renderer.renderLine(x1, y2, x1, y1, Color_Red);
    }
}

bool DebugSpriteSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<BoxShapeComponent2>()
        && components.any<TransformComponent2>();
}
