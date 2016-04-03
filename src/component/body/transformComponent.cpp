//
//  transformComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 30/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "transformComponent.h"

TransformComponent::TransformComponent()
{
}

TransformComponent::~TransformComponent()
{
}

const Vec2f& TransformComponent::getPosition() const
{
    return m_position;
}

float TransformComponent::getPositionX() const
{
    return m_position.x;
}

float TransformComponent::getPositionY() const
{
    return m_position.y;
}

void TransformComponent::setPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
}

void TransformComponent::setPositionX(float x)
{
    m_position.x = x;
}

void TransformComponent::setPositionY(float y)
{
    m_position.y = y;
}

const Vec2f& TransformComponent::getRotation() const
{
    return m_rotation;
}

float TransformComponent::getRotationX() const
{
    return m_rotation.x;
}

float TransformComponent::getRotationY() const
{
    return m_rotation.y;
}

void TransformComponent::setRotation(float x, float y)
{
    m_rotation.x = x;
    m_rotation.y = y;
}

void TransformComponent::setRotationX(float x)
{
    m_rotation.x = x;
}

void TransformComponent::setRotationY(float y)
{
    m_rotation.y = y;
}

const Vec2f& TransformComponent::getScale() const
{
    return m_scale;
}

float TransformComponent::getScaleX() const
{
    return m_scale.x;
}

float TransformComponent::getScaleY() const
{
    return m_scale.y;
}

void TransformComponent::setScale(float x, float y)
{
    m_scale.x = x;
    m_scale.y = y;
}

void TransformComponent::setScaleX(float x)
{
    m_scale.x = x;
}

void TransformComponent::setScaleY(float y)
{
    m_scale.y = y;
}
