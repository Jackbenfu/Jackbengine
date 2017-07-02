//
// color.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "color.hpp"

using namespace Jackbengine;

Color::Color()
    : r(0),
      g(0),
      b(0),
      a(0)
{
    // Nothing
}

Color::Color(byte r, byte g, byte b)
    : r(r),
      g(g),
      b(b),
      a(255)
{
    // Nothing
}

Color::Color(byte r, byte g, byte b, byte a)
    : r(r),
      g(g),
      b(b),
      a(a)
{
    // Nothing
}

Color::~Color() = default;
