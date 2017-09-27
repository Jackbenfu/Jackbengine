//
// containerComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "containerComponent2.hpp"

using namespace Jackbengine;

ContainerComponent2::ContainerComponent2(int x, int y, int w, int h)
    : m_rect {x, y, w, h}
{ }

const Recti& ContainerComponent2::rect() const
{
    return m_rect;
}

void ContainerComponent2::setRect(int x, int y, int w, int h)
{
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = w;
    m_rect.h = h;
}

bool ContainerComponent2::contains(float x, float y) const
{
    return x >= m_rect.x &&
           x <= m_rect.x + m_rect.w &&
           y >= m_rect.y &&
           y <= m_rect.y + m_rect.h;
}

bool ContainerComponent2::contains(const Vec2i& point) const
{
    return contains((float)point.x, (float)point.y);
}

bool ContainerComponent2::contains(const Vec2f& point) const
{
    return contains(point.x, point.y);
}

int ContainerComponent2::x() const
{
    return m_rect.x;
}

int ContainerComponent2::y() const
{
    return m_rect.y;
}

int ContainerComponent2::width() const
{
    return m_rect.w;
}

int ContainerComponent2::height() const
{
    return m_rect.h;
}
