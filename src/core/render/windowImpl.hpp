//
// windowImpl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 16/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_IMPL_H__
#define __WINDOW_IMPL_H__

#include "window.hpp"
#include "core/math/vector2d.hpp"
#include "platform.hpp"

namespace Jackbengine {

class WindowImpl : public Window
{
    friend class Window;

public:
    ~WindowImpl() override;

    bool init(const char *title, int width, int height, bool fullscreen) override;

    void showCursor(bool visible) override;

    SDL_Window* getRawWindow() const;

private:
    WindowImpl();

    void setWindowIcon();

    SDL_Window *m_window = nullptr;
};

} // namespace Jackbengine

#endif // __WINDOW_IMPL_H__
