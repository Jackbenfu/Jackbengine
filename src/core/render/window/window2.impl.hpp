//
// window2.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_2_IMPL_H__
#define __WINDOW_2_IMPL_H__

#include "window2.hpp"
#include "platform.hpp"

namespace Jackbengine {

class Window2::Impl
{
public:
    Impl(const std::string& title, int width, int height, bool fullscreen);
    ~Impl();

    int width() const;
    int height() const;

    SDL_Window* internalObject() const;

private:
    void setWindowIcon();

    SDL_Window *m_window {nullptr};

    int m_width {0};
    int m_height {0};
};

} // namespace Jackbengine

#endif // __WINDOW_2_IMPL_H__
