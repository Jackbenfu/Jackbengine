//
// transformComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "transformComponent2.hpp"

using namespace Jackbengine;

TransformComponent2::TransformComponent2(float positionX, float positionY)
    : TransformComponent2 {positionX, positionY, 1.0f, 1.0f, 0.0}
{ }

TransformComponent2::TransformComponent2(float positionX, float positionY, double angle)
    : TransformComponent2 {positionX, positionY, 1.0f, 1.0f, angle}
{ }

TransformComponent2::TransformComponent2(float positionX, float positionY, float scaleX, float scaleY)
    : TransformComponent2 {positionX, positionY, scaleX, scaleY, 0.0}
{ }

TransformComponent2::TransformComponent2(
    float positionX, float positionY, float scaleX, float scaleY, double angle)
    : m_position {positionX, positionY},
      m_scale {scaleX, scaleY},
      m_angle {angle}
{ }

const Vec2f& TransformComponent2::position() const
{
    return m_position;
}

float TransformComponent2::positionX() const
{
    return m_position.x;
}

float TransformComponent2::positionY() const
{
    return m_position.y;
}

void TransformComponent2::setPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
}

void TransformComponent2::setPositionX(float x)
{
    m_position.x = x;
}

void TransformComponent2::setPositionY(float y)
{
    m_position.y = y;
}

double TransformComponent2::angle() const
{
    return m_angle;
}

void TransformComponent2::setAngle(double angle)
{
    m_angle = angle;
}

const Vec2f& TransformComponent2::scale() const
{
    return m_scale;
}

float TransformComponent2::scaleX() const
{
    return m_scale.x;
}

float TransformComponent2::scaleY() const
{
    return m_scale.y;
}

void TransformComponent2::setScale(float x, float y)
{
    m_scale.x = x;
    m_scale.y = y;
}

void TransformComponent2::setScaleX(float x)
{
    m_scale.x = x;
}

void TransformComponent2::setScaleY(float y)
{
    m_scale.y = y;
}
