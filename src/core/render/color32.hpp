//
// color32.hpp
// jackbengine
//
// Created by Damien Bendejacq on 18/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_H__
#define __COLOR_H__

#include "common.hpp"

namespace Jackbengine {

struct Color32
{
    Color32();
    Color32(const Color32&) = default;
    Color32(byte r, byte g, byte b);
    Color32(byte r, byte g, byte b, byte a);

    ~Color32();

    byte r;
    byte g;
    byte b;
    byte a;
};

// Common colors
#define Color_Black         Color32(0, 0, 0)
#define Color_Blue          Color32(0, 0, 255)
#define Color_Green         Color32(0, 255, 0)
#define Color_Red           Color32(255, 0, 0)
#define Color_YellowGold    Color32(221, 173, 29)
#define Color_White         Color32(255, 255, 255)
#define Color_DarkGrey      Color32(100, 100, 100)

} // namespace Jackbengine

#endif // __COLOR_H__
