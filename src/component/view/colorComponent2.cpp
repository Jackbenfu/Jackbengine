//
// colorComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 01/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "colorComponent2.hpp"

using namespace Jackbengine;

ColorComponent2::ColorComponent2(Color color)
    : ColorComponent2(color.r, color.g, color.b, color.a)
{
    // Nothing
}

ColorComponent2::ColorComponent2(byte red, byte green, byte blue, byte alpha)
    : m_color {red, green, blue, alpha}
{
    // Nothing
}

ColorComponent2::ColorComponent2(byte red, byte green, byte blue)
    : m_color {red, green, blue}
{
    // Nothing
}

Color ColorComponent2::getColor() const
{
    return m_color;
}

byte ColorComponent2::getRed() const
{
    return m_color.r;
}

void ColorComponent2::setRed(byte value)
{
    m_color.r = value;
}

byte ColorComponent2::getGreen() const
{
    return m_color.g;
}

void ColorComponent2::setGreen(byte value)
{
    m_color.g = value;
}

byte ColorComponent2::getBlue() const
{
    return m_color.b;
}

void ColorComponent2::setBlue(byte value)
{
    m_color.b = value;
}

byte ColorComponent2::getAlpha() const
{
    return m_color.a;
}

void ColorComponent2::setAlpha(byte value)
{
    m_color.a = value;
}
