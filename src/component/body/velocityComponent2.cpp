//
// velocityComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "velocityComponent2.hpp"

using namespace Jackbengine;

VelocityComponent2::VelocityComponent2(float x, float y)
{
    // Nothing
}

const Vec2f& VelocityComponent2::get() const
{
    return m_velocity;
}

void VelocityComponent2::set(float x, float y)
{
    m_velocity.x = x;
    m_velocity.y = y;
}

float VelocityComponent2::getX() const
{
    return m_velocity.x;
}

void VelocityComponent2::setX(float x)
{
    m_velocity.x = x;
}

float VelocityComponent2::getY() const
{
    return m_velocity.y;
}

void VelocityComponent2::setY(float y)
{
    m_velocity.y = y;
}
