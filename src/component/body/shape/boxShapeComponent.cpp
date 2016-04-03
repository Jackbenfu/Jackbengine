//
//  boxShapeComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 05/02/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "boxShapeComponent.h"

BoxShapeComponent::BoxShapeComponent()
{
}

BoxShapeComponent::~BoxShapeComponent()
{
}

float BoxShapeComponent::getWidth() const
{
    return m_vector.x;
}

float BoxShapeComponent::getHeight() const
{
    return m_vector.y;
}

const Vec2f& BoxShapeComponent::getSize() const
{
    return m_vector;
}

void BoxShapeComponent::setWidth(float width)
{
    if (0.0f <= width)
    {
        m_vector.x = width;
    }
}

void BoxShapeComponent::setHeight(float height)
{
    if (0.0f <= height)
    {
        m_vector.y = height;
    }
}

void BoxShapeComponent::setSize(float width, float height)
{
    setWidth(width);
    setHeight(height);
}
