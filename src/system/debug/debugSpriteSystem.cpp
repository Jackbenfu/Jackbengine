//
// debugSpriteSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 24/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "debugSpriteSystem.hpp"
#include "component/body/shape/boxShapeComponent.hpp"
#include "component/body/transformComponent.hpp"

using namespace Jackbengine;

DebugSpriteSystem::DebugSpriteSystem() = default;

DebugSpriteSystem::~DebugSpriteSystem() = default;

void DebugSpriteSystem::update(float)
{
    for (auto entity : m_entities)
    {
        if (entity->isEnabled())
        {
            auto boxShape = entity->getComponentIfEnabled<BoxShapeComponent>();
            auto transform = entity->getComponentIfEnabled<TransformComponent>();

            if (!boxShape || !transform)
            {
                continue;
            }

            auto position = transform->getPosition();
            auto size = boxShape->getSize();

            auto x1 = position.x;
            auto x2 = position.x + size.x;
            auto y1 = position.y;
            auto y2 = position.y + size.y;

            m_renderer->renderLine(x1, y1, x2, y1, Color32(255, 0, 0));
            m_renderer->renderLine(x2, y1, x2, y2, Color32(255, 0, 0));
            m_renderer->renderLine(x2, y2, x1, y2, Color32(255, 0, 0));
            m_renderer->renderLine(x1, y2, x1, y1, Color32(255, 0, 0));
        }
    }
}

bool DebugSpriteSystem::hasRequiredComponents(Entity *entity)
{
    return entity->getComponentIfEnabled<BoxShapeComponent>() &&
        entity->getComponentIfEnabled<TransformComponent>();
}

void DebugSpriteSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
