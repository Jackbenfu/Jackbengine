//
// spriteDebugSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "spriteDebugSystem.hpp"
#include "component/view/spriteComponent.hpp"
#include "component/body/transformComponent.hpp"

namespace Jackbengine {

SpriteDebugSystem::SpriteDebugSystem(const Renderer& renderer)
    : m_renderer {renderer},
      m_color {Color(255, 0, 0)}
{
}

int SpriteDebugSystem::order() const
{
    return (int) SystemOrder::SpriteDebug;
}

void SpriteDebugSystem::frame(float)
{
    for (const auto&[entity, components] : entities())
    {
        const auto sprite = components->get<SpriteComponent>();
        const auto transform = components->get<TransformComponent>();

        const auto position = transform->position();
        const auto width = sprite->texture().width();
        const auto height = sprite->texture().height();

        const auto x1 = position.x;
        const auto x2 = position.x + width;
        const auto y1 = position.y;
        const auto y2 = position.y + height;

        m_renderer.renderLine(x1, y1, x2, y1, m_color);
        m_renderer.renderLine(x2, y1, x2, y2, m_color);
        m_renderer.renderLine(x2, y2, x1, y2, m_color);
        m_renderer.renderLine(x1, y2, x1, y1, m_color);
    }
}

bool SpriteDebugSystem::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<SpriteComponent>()
           && components.any<TransformComponent>();
}

}
