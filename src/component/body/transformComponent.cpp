//
// transformComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 30/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "transformComponent.hpp"

using namespace Jackbengine;

TransformComponent::TransformComponent() = default;

TransformComponent::~TransformComponent() = default;

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

double TransformComponent::getRotation() const
{
    return m_angle;
}

void TransformComponent::setRotation(double angle)
{
    m_angle = angle;
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
