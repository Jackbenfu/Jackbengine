//
//  rendererImpl.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 14/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "rendererImpl.h"
#include "windowImpl.h"
#include "textureImpl.h"

RendererImpl::RendererImpl()
{
}

RendererImpl::~RendererImpl()
{
    SDL_DestroyRenderer(m_renderer);
}

bool RendererImpl::init(const Window *window)
{
    WindowImpl *windowImpl = (WindowImpl*)window;
    if (!windowImpl)
    {
        printf("%s\n", SDL_GetError());
        return false;
    }

    SDL_Window *sdlRawWindow = windowImpl->getRawWindow();
    if (!sdlRawWindow)
    {
        return false;
    }

    SDL_GetWindowSize(sdlRawWindow, &m_width, &m_height);
    m_renderer = SDL_CreateRenderer(sdlRawWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer)
    {
        printf("%s\n", SDL_GetError());
        return false;
    }

    return true;
}

void RendererImpl::clear()
{
    setRenderColor(m_clearColor);
    SDL_RenderClear(m_renderer);
}

void RendererImpl::setClearColor(Color color)
{
    m_clearColor = color;
}

void RendererImpl::present()
{
    SDL_RenderPresent(m_renderer);
}

void RendererImpl::setRenderColor(Color color)
{
    if (SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a) < 0)
    {
        printf("%s\n", SDL_GetError());
    }
}

void RendererImpl::renderTexture(int x, int y, const Texture *texture)
{
    TextureImpl *textureImpl = (TextureImpl*)texture;
    if (textureImpl)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = texture->getWidth();
        rect.h = texture->getHeight();

        SDL_RenderCopy(m_renderer, textureImpl->getRawTexture(), nullptr, &rect);
    }
}

void RendererImpl::renderLine(float x1, float y1, float x2, float y2, Color color)
{
    setRenderColor(color);

    SDL_RenderDrawLine(m_renderer, static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
}

void RendererImpl::renderPoint(float x, float y, Color color)
{
    setRenderColor(color);

    SDL_RenderDrawPoint(m_renderer, static_cast<int>(x), static_cast<int>(y));
}

int RendererImpl::getWidth() const
{
    return m_width;
}

int RendererImpl::getHeight() const
{
    return m_height;
}

SDL_Renderer* RendererImpl::getRawRenderer() const
{
    return m_renderer;
}
