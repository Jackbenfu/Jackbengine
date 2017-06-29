//
// containerComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 26/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "containerComponent.h"

ContainerComponent::ContainerComponent()
{
}

ContainerComponent::~ContainerComponent()
{
}

const Recti& ContainerComponent::getRect() const
{
    return m_rect;
}

void ContainerComponent::setRect(int x, int y, int w, int h)
{
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = w;
    m_rect.h = h;
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
    return contains(static_cast<float>(point.x), static_cast<float>(point.y));
}

bool ContainerComponent::contains(const Vec2f& point) const
{
    return contains(point.x, point.y);
}

int ContainerComponent::getX() const
{
    return m_rect.x;
}

int ContainerComponent::getY() const
{
    return m_rect.y;
}

int ContainerComponent::getWidth() const
{
    return m_rect.w;
}

int ContainerComponent::getHeight() const
{
    return m_rect.h;
}
