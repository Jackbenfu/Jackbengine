//
//  debugTextSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 24/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "debugTextSystem.h"
#include "component/layout/containerComponent.h"
#include "component/view/textComponent.h"
#include "component/body/transformComponent.h"

DebugTextSystem::DebugTextSystem()
{
}

DebugTextSystem::~DebugTextSystem()
{
}

void DebugTextSystem::update(float delta)
{
    UNUSED(delta)

    for (auto entity : m_entities)
    {
        if (em()->isEntityEnabled(entity))
        {
            Vec2f position;
            float w;
            float h;

            auto container = em()->getComponentIfEnabled<ContainerComponent>(entity);
            if (container)
            {
                position.x = container->getX();
                position.y = container->getY();
                w = container->getWidth();
                h = container->getHeight();
            }
            else
            {
                auto transform = em()->getComponentIfEnabled<TransformComponent>(entity);
                auto text = em()->getComponentIfEnabled<TextComponent>(entity);
                if (!transform || !text)
                {
                    continue;
                }

                position.x = transform->getPositionX();
                position.y = transform->getPositionY();
                w = text->getWidth();
                h = text->getHeight();
            }

            auto x1 = position.x;
            auto x2 = position.x + w;
            auto y1 = position.y;
            auto y2 = position.y + h;

            m_renderer->renderLine(x1, y1, x2, y1, Color_Red);
            m_renderer->renderLine(x2, y1, x2, y2, Color_Red);
            m_renderer->renderLine(x2, y2, x1, y2, Color_Red);
            m_renderer->renderLine(x1, y2, x1, y1, Color_Red);
        }
    }
}

bool DebugTextSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponentIfEnabled<TextComponent>(entity) &&
        (em()->getComponentIfEnabled<ContainerComponent>(entity) ||
         em()->getComponentIfEnabled<TransformComponent>(entity));
}

void DebugTextSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
