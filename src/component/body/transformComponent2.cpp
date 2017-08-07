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
    : m_position {positionX, positionY}
{
    // Nothing
}

TransformComponent2::TransformComponent2(float positionX, float positionY, double angle)
    : m_position {positionX, positionY},
      m_angle {angle}
{
    // Nothing
}

TransformComponent2::TransformComponent2(float positionX, float positionY, float scaleX, float scaleY)
    : m_position {positionX, positionY},
      m_scale {scaleX, scaleY}
{
    // Nothing
}

TransformComponent2::TransformComponent2(
    float positionX, float positionY, float scaleX, float scaleY, double angle)
    : m_position {positionX, positionY},
      m_scale {scaleX, scaleY},
      m_angle {angle}
{
    // Nothing
}

const Vec2f& TransformComponent2::getPosition() const
{
    return m_position;
}

float TransformComponent2::getPositionX() const
{
    return m_position.x;
}

float TransformComponent2::getPositionY() const
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

double TransformComponent2::getAngle() const
{
    return m_angle;
}

void TransformComponent2::setAngle(double angle)
{
    m_angle = angle;
}

const Vec2f& TransformComponent2::getScale() const
{
    return m_scale;
}

float TransformComponent2::getScaleX() const
{
    return m_scale.x;
}

float TransformComponent2::getScaleY() const
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
