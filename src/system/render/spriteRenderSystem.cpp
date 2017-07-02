//
// spriteRenderSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 02/05/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "spriteRenderSystem.hpp"
#include "component/view/spriteComponent.hpp"
#include "component/body/transformComponent.hpp"

using namespace Jackbengine;

SpriteRenderSystem::SpriteRenderSystem() = default;

SpriteRenderSystem::~SpriteRenderSystem() = default;

void SpriteRenderSystem::update(float delta)
{
    UNUSED(delta);

    for (auto entity : m_entities)
    {
        if (entity->isEnabled())
        {
            auto sprite = entity->getComponentIfEnabled<SpriteComponent>();
            auto transform = entity->getComponentIfEnabled<TransformComponent>();

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
    return entity->getComponentIfEnabled<SpriteComponent>() &&
        entity->getComponentIfEnabled<TransformComponent>();
}

void SpriteRenderSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
