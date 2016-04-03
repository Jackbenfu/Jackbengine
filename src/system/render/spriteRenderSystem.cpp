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
            SpriteComponent *sprite = em()->getComponent<SpriteComponent>(entity);
            TransformComponent *transform = em()->getComponent<TransformComponent>(entity);

            if (sprite->isEnabled())
            {
                m_renderer->renderTexture(
                    static_cast<int>(transform->getPositionX()),
                    static_cast<int>(transform->getPositionY()),
                    sprite->getTexture()
                );
            }
        }
    }
}

bool SpriteRenderSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponent<SpriteComponent>(entity) &&
        em()->getComponent<TransformComponent>(entity);
}

void SpriteRenderSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
