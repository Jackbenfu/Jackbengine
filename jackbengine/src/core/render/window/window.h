//
// window.h
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
//

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Surface SDL_Surface;
typedef void* SDL_GLContext;

namespace Jackbengine::details {

class Window
{
public:
    Window(const std::string& title, int width, int height, bool fullscreen);
    ~Window();

    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

    [[nodiscard]] SDL_Window* nativeWindow() const;
    [[nodiscard]] SDL_Surface* nativeSurface() const;
    [[nodiscard]] SDL_GLContext nativeGLContext() const;

private:
    static void setWindowIcon();

    SDL_Window* m_window {nullptr};
    SDL_Surface* m_surface {nullptr};
    SDL_GLContext m_glContext {nullptr};

    int m_width {0};
    int m_height {0};
};

}

#endif // __WINDOW_H__
