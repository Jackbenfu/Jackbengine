//
// color.h
// jackbengine
//
// Created by Damien Bendejacq on 18/06/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_H__
#define __COLOR_H__

namespace Jackbengine {

struct Color
{
    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

}

#endif // __COLOR_H__
