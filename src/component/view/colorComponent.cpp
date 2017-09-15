//
// colorComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/05/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "colorComponent.hpp"

using namespace Jackbengine;

ColorComponent::ColorComponent() = default;

ColorComponent::~ColorComponent() = default;

Color32 ColorComponent::getColor() const
{
    return m_color;
}

void ColorComponent::setColor(Color32 color)
{
    m_color = color;
}

void ColorComponent::setColor(byte red, byte green, byte blue, byte alpha)
{
    m_color = Color32(red, green, blue, alpha);
}

void ColorComponent::setColor(byte red, byte green, byte blue)
{
    m_color = Color32(red, green, blue);
}

byte ColorComponent::getRed() const
{
    return m_color.r;
}

void ColorComponent::setRed(byte value)
{
    m_color.r = value;
}

byte ColorComponent::getGreen() const
{
    return m_color.g;
}

void ColorComponent::setGreen(byte value)
{
    m_color.g = value;
}

byte ColorComponent::getBlue() const
{
    return m_color.b;
}

void ColorComponent::setBlue(byte value)
{
    m_color.b = value;
}

byte ColorComponent::getAlpha() const
{
    return m_color.a;
}

void ColorComponent::setAlpha(byte value)
{
    m_color.a = value;
}
