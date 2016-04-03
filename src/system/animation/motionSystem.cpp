//
//  motionSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/05/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
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
        if (em()->isEntityEnabled(entity))
        {
            TransformComponent *transform = em()->getComponent<TransformComponent>(entity);
            VelocityComponent *velocity = em()->getComponent<VelocityComponent>(entity);

            if (velocity->isEnabled())
            {
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
}

bool MotionSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponent<TransformComponent>(entity) &&
        em()->getComponent<VelocityComponent>(entity);
}
