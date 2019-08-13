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

Color::Color(unsigned char r, unsigned char g, unsigned char b)
    : r(r),
      g(g),
      b(b),
      a(255)
{
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    : r(r),
      g(g),
      b(b),
      a(a)
{
}

}
