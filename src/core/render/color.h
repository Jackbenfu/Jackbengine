//
// color.h
// jackbengine
//
// Created by Damien Bendejacq on 18/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_H__
#define __COLOR_H__

#include "common.h"

NS_BEGIN_JKB

struct Color
{
    Color();
    Color(byte r, byte g, byte b);
    Color(byte r, byte g, byte b, byte a);
    ~Color();

    byte r;
    byte g;
    byte b;
    byte a;
};

// Common colors
#define Color_Black         Color(0, 0, 0)
#define Color_Blue          Color(0, 0, 255)
#define Color_Green         Color(0, 255, 0)
#define Color_Red           Color(255, 0, 0)
#define Color_YellowGold    Color(221, 173, 29)
#define Color_White         Color(255, 255, 255)
#define Color_DarkGrey      Color(100, 100, 100)

NS_END_JKB

#endif // __COLOR_H__
