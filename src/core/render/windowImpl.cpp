//
// sdlWindow.cpp
// jackbengine
//
// Created by Damien Bendejacq on 16/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "windowImpl.h"

WindowImpl::WindowImpl()
{
}

WindowImpl::~WindowImpl()
{
    SDL_DestroyWindow(m_window);
}

bool WindowImpl::init(const char *title, int width, int height, bool fullscreen)
{
    SDL_WindowFlags flags;
    int x;
    int y;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
        x = 0;
        y = 0;
    }
    else
    {
        flags = SDL_WINDOW_HIDDEN;
        x = SDL_WINDOWPOS_CENTERED;
        y = SDL_WINDOWPOS_CENTERED;
    }

    m_window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (!m_window)
    {
        LOG_ERROR("%s", SDL_GetError())
        return false;
    }

    setWindowIcon();

    SDL_ShowWindow(m_window);

    return true;
}

void WindowImpl::showCursor(bool visible)
{
    SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
}

SDL_Window* WindowImpl::getRawWindow() const
{
    return m_window;
}

void WindowImpl::setWindowIcon()
{
#ifdef _WIN32

    // Thanks to this Gist: https://gist.github.com/noct/9884320

    HINSTANCE handle = GetModuleHandle(nullptr);
    if (!handle)
    {
        LOG_ERROR("GetModuleHandle Win32 function: %lu", GetLastError())
    }

    const uint maskR = 0x00ff0000;
    const uint maskG = 0x0000ff00;
    const uint maskB = 0x000000ff;
    const uint maskA = 0xff000000;
    const int size = 32;
    const int bpp = 32;

    HICON icon = (HICON)LoadImage(handle, "icon", IMAGE_ICON, size, size, LR_SHARED);
    if (!icon)
    {
        LOG_ERROR("LoadImage Win32 function: %lu", GetLastError())
    }

    ICONINFO iconInfo;
    if (!GetIconInfo(icon, &iconInfo))
    {
        LOG_ERROR("GetIconInfo Win32 function: %lu", GetLastError())
    }

    HDC deviceContext = CreateCompatibleDC(nullptr);
    if (!deviceContext)
    {
        LOG_ERROR("CreateCompatibleDC Win32 function: %lu", GetLastError())
    }

    SDL_Surface *surface = SDL_CreateRGBSurface(0, size, size, bpp, maskR, maskG, maskB, maskA);
    if (!surface)
    {
        LOG_ERROR("%s", IMG_GetError())
    }

    BITMAPINFO bmi;
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
