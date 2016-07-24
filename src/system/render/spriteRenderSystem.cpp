//
//  spriteRenderSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 02/05/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "spriteRenderSystem.h"
#include "component/view/spriteComponent.h"
#include "component/body/transformComponent.h"

SpriteRenderSystem::SpriteRenderSystem()
{
}

SpriteRenderSystem::~SpriteRenderSystem()
{
}

void SpriteRenderSystem::update(float delta)
{
    UNUSED(delta)

    for (auto entity : m_entities)
    {
        if (em()->isEntityEnabled(entity))
        {
            auto sprite = em()->getComponentIfEnabled<SpriteComponent>(entity);
            auto transform = em()->getComponentIfEnabled<TransformComponent>(entity);

            if (!sprite || !transform)
            {
                continue;
            }

            m_renderer->renderTexture(
                static_cast<int>(transform->getPositionX()),
                static_cast<int>(transform->getPositionY()),
                sprite->getTexture(),
                transform->getRotation()
            );
        }
    }
}

bool SpriteRenderSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponentIfEnabled<SpriteComponent>(entity) &&
        em()->getComponentIfEnabled<TransformComponent>(entity);
}

void SpriteRenderSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
