//
// motionSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "motionSystem.hpp"
#include "component/body/transformComponent.hpp"
#include "component/body/velocityComponent.hpp"
#include "component/layout/containerComponent.hpp"

using namespace Jackbengine;

int MotionSystem::order() const
{
    return (int) SystemOrder::Motion;
}

void MotionSystem::frame(float delta)
{
    for (const auto&[entity, components] : entities())
    {
        const auto velocity = components->get<VelocityComponent>();
        const auto velocityVec = velocity->get();
        if (velocityVec.isZero())
        {
            continue;
        }

        auto transform = components->get<TransformComponent>();
        const auto transformPos = transform->position();
        transform->setPosition(
            transformPos.x + velocityVec.x * delta,
            transformPos.y + velocityVec.y * delta
        );

        auto container = components->get<ContainerComponent>();
        const auto containerPos = container->position();
        container->setPosition(containerPos.x, containerPos.y);
    }
}

bool MotionSystem::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<TransformComponent>()
           && components.any<VelocityComponent>();
}
