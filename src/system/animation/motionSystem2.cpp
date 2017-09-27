//
// motionSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "motionSystem2.hpp"
#include "component/body/transformComponent2.hpp"
#include "component/body/velocityComponent2.hpp"

using namespace Jackbengine;

void MotionSystem2::frame(float delta)
{
    for (const auto& entity : m_entities)
    {
        const auto components = entity.second;

        auto& transform = components->get<TransformComponent2>();
        const auto& velocity = components->get<VelocityComponent2>();

        const auto velocityVec = velocity.get();
        if (velocityVec.isZero())
        {
            continue;
        }

        const auto positionVec = transform.position();

        transform.setPosition(
            positionVec.x + velocityVec.x * delta,
            positionVec.y + velocityVec.y * delta
        );
    }
}

bool MotionSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<TransformComponent2>()
        && components.any<VelocityComponent2>();
}
