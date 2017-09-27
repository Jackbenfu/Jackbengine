//
// colorComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 01/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "colorComponent2.hpp"

using namespace Jackbengine;

ColorComponent2::ColorComponent2(Color32 color)
    : ColorComponent2(color.r, color.g, color.b, color.a)
{ }

ColorComponent2::ColorComponent2(byte red, byte green, byte blue, byte alpha)
    : m_color {red, green, blue, alpha}
{ }

ColorComponent2::ColorComponent2(byte red, byte green, byte blue)
    : m_color {red, green, blue}
{ }

Color32 ColorComponent2::getColor() const
{
    return m_color;
}

byte ColorComponent2::red() const
{
    return m_color.r;
}

void ColorComponent2::setRed(byte value)
{
    m_color.r = value;
}

byte ColorComponent2::green() const
{
    return m_color.g;
}

void ColorComponent2::setGreen(byte value)
{
    m_color.g = value;
}

byte ColorComponent2::blue() const
{
    return m_color.b;
}

void ColorComponent2::setBlue(byte value)
{
    m_color.b = value;
}

byte ColorComponent2::alpha() const
{
    return m_color.a;
}

void ColorComponent2::setAlpha(byte value)
{
    m_color.a = value;
}
