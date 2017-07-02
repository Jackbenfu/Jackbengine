//
// debugTextSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 24/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "debugTextSystem.hpp"
#include "component/layout/containerComponent.hpp"
#include "component/view/textComponent.hpp"
#include "component/body/transformComponent.hpp"

using namespace Jackbengine;

DebugTextSystem::DebugTextSystem() = default;

DebugTextSystem::~DebugTextSystem() = default;

void DebugTextSystem::update(float delta)
{
    UNUSED(delta);

    for (auto entity : m_entities)
    {
        if (entity->isEnabled())
        {
            Vec2f position;
            float w;
            float h;

            auto container = entity->getComponentIfEnabled<ContainerComponent>();
            if (container)
            {
                position.x = container->getX();
                position.y = container->getY();
                w = container->getWidth();
                h = container->getHeight();
            }
            else
            {
                auto transform = entity->getComponentIfEnabled<TransformComponent>();
                auto text = entity->getComponentIfEnabled<TextComponent>();
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
    return entity->getComponentIfEnabled<TextComponent>() &&
        (entity->getComponentIfEnabled<ContainerComponent>() ||
         entity->getComponentIfEnabled<TransformComponent>());
}

void DebugTextSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
