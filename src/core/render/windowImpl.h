//
//  windowImpl.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 16/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_IMPL_H__
#define __WINDOW_IMPL_H__

#include "window.h"
#include "core/math/vector2d.h"
#include "platform.h"

NS_BEGIN_JKB

class WindowImpl : public Window
{
    friend class Window;

public:
    ~WindowImpl();

    bool init(const char *title, int width, int height, bool fullscreen) override;

    void showCursor(bool visible) override;

    SDL_Window* getRawWindow() const;

private:
    WindowImpl();

    void setWindowIcon();

    SDL_Window *m_window = nullptr;
};

NS_END_JKB

#endif // __WINDOW_IMPL_H__
