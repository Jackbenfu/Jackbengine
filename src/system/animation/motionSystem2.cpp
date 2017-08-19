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

void MotionSystem2::update(float delta)
{
    for (auto pair : m_entities)
    {
        auto components = pair.second;

        auto& transform = components->get<TransformComponent2>();
        auto& velocity = components->get<VelocityComponent2>();

        auto velocityVec = velocity.get();
        if (velocityVec.isZero())
        {
            return;
        }

        auto positionVec = transform.getPosition();

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
