//
// window.hpp
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>
#include "core/sdl/sdl.hpp"
#include "common.hpp"

namespace Jackbengine {

class Window
{
    friend class Renderer;
    friend class GlRenderSystem;

public:
    Window(const std::string& title, int width, int height, bool fullscreen);
    ~Window();

    int width() const;
    int height() const;

private:
    void setWindowIcon();

    SDL_Window *m_window {nullptr};
    SDL_GLContext m_glContext {nullptr};

    int m_width {0};
    int m_height {0};
};

}

#endif // __WINDOW_H__
