//
// rect.h
// jackbengine
//
// Created by Damien Bendejacq on 26/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __RECT_H__
#define __RECT_H__

#include "common.h"

NS_BEGIN_JKB

template<typename T>
struct Rect
{
    Rect() : x(0), y(0), w(0), h(0) { }
    Rect(T x, T y, T w, T h) : x(x), y(y), w(w), h(h) { }
    ~Rect() { }

    T x;
    T y;
    T w;
    T h;
};

using Recti = Rect<int>;
using Rectf = Rect<float>;

NS_END_JKB

#endif // __RECT_H__
