//
// motionSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/05/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "motionSystem.h"
#include "component/body/transformComponent.h"
#include "component/body/velocityComponent.h"

MotionSystem::MotionSystem()
{
}

MotionSystem::~MotionSystem()
{
}

void MotionSystem::update(float delta)
{
    for (auto entity : m_entities)
    {
        if (entity->isEnabled())
        {
            auto transform = entity->getComponentIfEnabled<TransformComponent>();
            auto *velocity = entity->getComponentIfEnabled<VelocityComponent>();

            if (!velocity || !transform)
            {
                continue;
            }

            Vec2f velocityVec = velocity->getVelocity();
            if (!velocityVec.isZero())
            {
                Vec2f positionVec = transform->getPosition();

                transform->setPosition(
                    positionVec.x + velocityVec.x * delta,
                    positionVec.y + velocityVec.y * delta
                );
            }
        }
    }
}

bool MotionSystem::hasRequiredComponents(Entity *entity)
{
    return entity->getComponentIfEnabled<TransformComponent>() &&
        entity->getComponentIfEnabled<VelocityComponent>();
}
