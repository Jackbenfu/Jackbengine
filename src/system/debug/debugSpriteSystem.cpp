//
//  debugSpriteSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 24/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "debugSpriteSystem.h"
#include "component/body/shape/boxShapeComponent.h"
#include "component/body/transformComponent.h"

DebugSpriteSystem::DebugSpriteSystem()
{
}

DebugSpriteSystem::~DebugSpriteSystem()
{
}

void DebugSpriteSystem::update(float delta)
{
    UNUSED(delta)

    for (auto entity : m_entities)
    {
        if (em()->isEntityEnabled(entity))
        {
            BoxShapeComponent *boxShape = em()->getComponent<BoxShapeComponent>(entity);
            TransformComponent *transform = em()->getComponent<TransformComponent>(entity);

            Vec2f position = transform->getPosition();
            Vec2f size = boxShape->getSize();

            float x1 = position.x;
            float x2 = position.x + size.x;
            float y1 = position.y;
            float y2 = position.y + size.y;

            m_renderer->renderLine(x1, y1, x2, y1, Color_Red);
            m_renderer->renderLine(x2, y1, x2, y2, Color_Red);
            m_renderer->renderLine(x2, y2, x1, y2, Color_Red);
            m_renderer->renderLine(x1, y2, x1, y1, Color_Red);
        }
    }
}

bool DebugSpriteSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponent<BoxShapeComponent>(entity) &&
        em()->getComponent<TransformComponent>(entity);
}

void DebugSpriteSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
