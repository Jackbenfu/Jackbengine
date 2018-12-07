//
// color.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/06/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "color.hpp"

namespace Jackbengine {

Color::Color()
    : r(0),
      g(0),
      b(0),
      a(0)
{
}

Color::Color(byte r, byte g, byte b)
    : r(r),
      g(g),
      b(b),
      a(255)
{
}

Color::Color(byte r, byte g, byte b, byte a)
    : r(r),
      g(g),
      b(b),
      a(a)
{
}

}
