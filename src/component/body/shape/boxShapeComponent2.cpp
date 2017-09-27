//
// boxShapeComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 28/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "boxShapeComponent2.hpp"

using namespace Jackbengine;

BoxShapeComponent2::BoxShapeComponent2(float width, float height)
    : m_vector {width, height}
{ }

float BoxShapeComponent2::width() const
{
    return m_vector.x;
}

float BoxShapeComponent2::height() const
{
    return m_vector.y;
}

const Vec2f& BoxShapeComponent2::size() const
{
    return m_vector;
}

void BoxShapeComponent2::setWidth(float width)
{
    if (width < 0.0f)
    {
        throw std::invalid_argument("width");
    }

    m_vector.x = width;
}

void BoxShapeComponent2::setHeight(float height)
{
    if (height < 0.0f)
    {
        throw std::invalid_argument("height");
    }

    m_vector.y = height;
}

void BoxShapeComponent2::setSize(float width, float height)
{
    setWidth(width);
    setHeight(height);
}
