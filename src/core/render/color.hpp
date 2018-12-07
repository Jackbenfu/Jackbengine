//
// color.hpp
// jackbengine
//
// Created by Damien Bendejacq on 18/06/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_H__
#define __COLOR_H__

#include "common.hpp"

namespace Jackbengine {

struct Color
{
    Color();
    Color(byte r, byte g, byte b);
    Color(byte r, byte g, byte b, byte a);

    byte r;
    byte g;
    byte b;
    byte a;
};

}

#endif // __COLOR_H__
