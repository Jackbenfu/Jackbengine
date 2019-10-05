//
// window.cpp
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <emscripten/html5.h>
#include <GLES3/gl3.h>
#else

#include "glad/glad.h"

#endif

#include "core/sdl/sdlinc.h"
#include "window.h"

namespace Jackbengine::details {

Window::Window(const std::string &title, int width, int height, bool fullscreen)
{
    SDL_WindowFlags flags;
    int x;
    int y;
    if (fullscreen)
    {
        flags = (SDL_WindowFlags) (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
        x = 0;
        y = 0;
    }
    else
    {
        flags = (SDL_WindowFlags) (SDL_WINDOW_OPENGL);
        x = SDL_WINDOWPOS_CENTERED;
        y = SDL_WINDOWPOS_CENTERED;
    }

#ifdef EMSCRIPTEN
    EmscriptenWebGLContextAttributes attrs;
    attrs.majorVersion = 2;
    attrs.minorVersion = 0;
    auto webgl_context = emscripten_webgl_create_context(0, &attrs);
    emscripten_webgl_make_context_current(webgl_context);
#else
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
#endif

    m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
    if (nullptr == m_window)
    {
        throw std::runtime_error(SDL_GetError());
    }

    m_glContext = SDL_GL_CreateContext(m_window);
    if (nullptr == m_glContext)
    {
        throw std::runtime_error(SDL_GetError());
    }

#ifndef EMSCRIPTEN
    auto gladStatus = gladLoadGLLoader(SDL_GL_GetProcAddress);
    if (!gladStatus)
    {
        throw std::runtime_error("Failed to initialize Glad");
    }
#endif

    SDL_GL_MakeCurrent(m_window, m_glContext);
    SDL_GL_SetSwapInterval(0);
    SDL_GetWindowSize(m_window, &m_width, &m_height);

    setWindowIcon();
    SDL_ShowWindow(m_window);
}

Window::~Window()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
}

int Window::width() const
{
    return m_width;
}

int Window::height() const
{
    return m_height;
}

SDL_Window *Window::nativeWindow() const
{
    return m_window;
}

SDL_GLContext Window::nativeGLContext() const
{
    return m_glContext;
}

void Window::setWindowIcon()
{
#ifdef _WIN32

    // Thanks to this Gist: https://gist.github.com/noct/9884320

    auto handle = GetModuleHandle(nullptr);
    if (!handle)
    {
        throw std::runtime_error(std::to_string(GetLastError()));
    }

    const unsigned int maskR = 0x00ff0000;
    const unsigned int maskG = 0x0000ff00;
    const unsigned int maskB = 0x000000ff;
    const unsigned int maskA = 0xff000000;
    const int size = 32;
    const int bpp = 32;

    auto icon = (HICON)LoadImage(handle, "icon", IMAGE_ICON, size, size, LR_SHARED);
    if (nullptr == icon)
    {
        throw std::runtime_error(std::to_string(GetLastError()));
    }

    ICONINFO iconInfo; // NOLINT
    if (FALSE == GetIconInfo(icon, &iconInfo))
    {
        throw std::runtime_error(std::to_string(GetLastError()));
    }

    auto deviceContext = CreateCompatibleDC(nullptr);
    if (nullptr == deviceContext)
    {
        throw std::runtime_error(std::to_string(GetLastError()));
    }

    auto surface = SDL_CreateRGBSurface(0, size, size, bpp, maskR, maskG, maskB, maskA);
    if (nullptr == surface)
    {
        throw std::runtime_error(IMG_GetError());
    }

    BITMAPINFO bmi; // NOLINT
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = size;
    bmi.bmiHeader.biHeight = -size;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = bpp;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage = 0;

    SelectObject(deviceContext, iconInfo.hbmColor);
    GetDIBits(deviceContext, iconInfo.hbmColor, 0, size, surface->pixels, &bmi, DIB_RGB_COLORS);
    SDL_SetWindowIcon(m_window, surface);

    SDL_FreeSurface(surface);
    DeleteDC(deviceContext);
    DeleteObject(iconInfo.hbmColor);
    DeleteObject(iconInfo.hbmMask);
    DestroyIcon(icon);

#endif
}

}
