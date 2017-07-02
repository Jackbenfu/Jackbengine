//
// window.hpp
// jackbengine
//
// Created by Damien Bendejacq on 16/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "core/math/vector2d.hpp"

namespace Jackbengine {

class Window
{
public:
    virtual ~Window();

    virtual bool init(const char *title, int width, int height, bool fullscreen) = 0;

    virtual void showCursor(bool visible) = 0;

    static Window* create();

protected:
    Window();
};

} // namespace Jackbengine

#endif // __WINDOW_H__
