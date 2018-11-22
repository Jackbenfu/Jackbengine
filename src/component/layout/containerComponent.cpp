//
// containerComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "containerComponent.hpp"

namespace Jackbengine {

ContainerComponent::ContainerComponent(float x, float y, float w, float h)
    : m_rect {x, y, w, h}
{
}

const Rectf& ContainerComponent::rect() const
{
    return m_rect;
}

void ContainerComponent::setRect(float x, float y, float w, float h)
{
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = w;
    m_rect.h = h;
}

const Vec2f ContainerComponent::position() const
{
    return Vec2f {m_rect.x, m_rect.y};
}

void ContainerComponent::setPosition(float x, float y)
{
    m_rect.x = x;
    m_rect.y = y;
}

bool ContainerComponent::contains(float x, float y) const
{
    return x >= m_rect.x &&
           x <= m_rect.x + m_rect.w &&
           y >= m_rect.y &&
           y <= m_rect.y + m_rect.h;
}

bool ContainerComponent::contains(const Vec2i& point) const
{
    return contains((float) point.x, (float) point.y);
}

bool ContainerComponent::contains(const Vec2f& point) const
{
    return contains(point.x, point.y);
}

float ContainerComponent::x() const
{
    return m_rect.x;
}

float ContainerComponent::y() const
{
    return m_rect.y;
}

float ContainerComponent::width() const
{
    return m_rect.w;
}

float ContainerComponent::height() const
{
    return m_rect.h;
}

}
