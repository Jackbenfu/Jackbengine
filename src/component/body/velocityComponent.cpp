//
// velocityComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/05/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "velocityComponent.hpp"

using namespace Jackbengine;

VelocityComponent::VelocityComponent() = default;

VelocityComponent::~VelocityComponent() = default;

const Vec2f& VelocityComponent::getVelocity() const
{
    return m_velocity;
}

void VelocityComponent::set(float x, float y)
{
    m_velocity.x = x;
    m_velocity.y = y;
}

float VelocityComponent::getX() const
{
    return m_velocity.x;
}

void VelocityComponent::setX(float x)
{
    m_velocity.x = x;
}

float VelocityComponent::getY() const
{
    return m_velocity.y;
}

void VelocityComponent::setY(float y)
{
    m_velocity.y = y;
}
