//
// window.h
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_H__
#define __WINDOW_H__

namespace Jackbengine {

class Window
{
    friend class Renderer;

public:
    Window(const std::string &title, int width, int height, bool fullscreen);
    ~Window();

    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

private:
    static void setWindowIcon();

    SDL_Window *m_window {nullptr};

    int m_width {0};
    int m_height {0};
};

}

#endif // __WINDOW_H__
