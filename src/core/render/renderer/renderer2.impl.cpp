//
// renderer2.impl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "renderer2.impl.hpp"
#include "core/render/texture/texture2.hpp"

using namespace Jackbengine;

Renderer2::Impl::Impl(const Window2& window)
{
    auto sdlWindow = static_cast<SDL_Window*>(window.getInternalObject());

    m_renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == m_renderer)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Renderer2::Impl::~Impl()
{
    SDL_DestroyRenderer(m_renderer);
}

void Renderer2::Impl::clear()
{
    setRenderColor(m_clearColor);

    if (SDL_RenderClear(m_renderer) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer2::Impl::present()
{
    SDL_RenderPresent(m_renderer);
}

void Renderer2::Impl::setClearColor(Color color)
{
    m_clearColor = color;
}

void Renderer2::Impl::setRenderColor(Color color)
{
    if (SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer2::Impl::renderTexture(int x, int y, const Texture2& texture)
{
    renderTexture(x, y, texture, 0.0);
}

void Renderer2::Impl::renderTexture(int x, int y, const Texture2& texture, double angle)
{
    const auto sdlTexture = static_cast<SDL_Texture*>(texture.getInternalObject());

    SDL_Rect rect {};
    rect.x = x;
    rect.y = y;
    rect.w = texture.getWidth();
    rect.h = texture.getHeight();

    SDL_RenderCopyEx(m_renderer, sdlTexture, nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);
}

void Renderer2::Impl::renderLine(float x1, float y1, float x2, float y2, Color color)
{
    setRenderColor(color);

    if (SDL_RenderDrawLine(m_renderer, (int)x1, (int)y1, (int)x2, (int)y2) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer2::Impl::renderPoint(float x, float y, Color color)
{
    setRenderColor(color);

    if (SDL_RenderDrawPoint(m_renderer, (int)x, (int)y) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

SDL_Renderer* Renderer2::Impl::getInternalObject() const
{
    return m_renderer;
}
