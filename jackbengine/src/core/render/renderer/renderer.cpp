//
// renderer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "pch.h"
#include "renderer.h"
#include "core/render/texture/texture.h"

namespace Jackbengine {

Renderer::Renderer(const Window &window)
{
    const auto sdlWindow = window.m_window;

    m_renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (nullptr == m_renderer)
    {
        throw std::runtime_error(SDL_GetError());
    }

    SDL_GetWindowSize(sdlWindow, &m_width, &m_height);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_renderer);
}

void Renderer::clear()
{
    setRenderColor(m_clearColor);

    if (SDL_RenderClear(m_renderer) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer::present()
{
    SDL_RenderPresent(m_renderer);
}

void Renderer::setClearColor(Color color)
{
    m_clearColor = color;
}

void Renderer::setRenderColor(Color color) const
{
    if (SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer::renderTexture(int x, int y, const Texture &texture) const
{
    renderTexture(x, y, texture, 0.0);
}

void Renderer::renderTexture(int x, int y, const Texture &texture, double angle) const
{
    const auto sdlTexture = texture.m_texture;

    SDL_Rect rect {};
    rect.x = x;
    rect.y = y;
    rect.w = texture.width();
    rect.h = texture.height();

    const SDL_Point pivot {0, 0};

    SDL_RenderCopyEx(m_renderer, sdlTexture, nullptr, &rect, angle, &pivot, SDL_FLIP_NONE);
}

void Renderer::renderLine(float x1, float y1, float x2, float y2, Color color) const
{
    setRenderColor(color);

    if (SDL_RenderDrawLine(m_renderer, (int) x1, (int) y1, (int) x2, (int) y2) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer::renderPoint(float x, float y, Color color) const
{
    setRenderColor(color);

    if (SDL_RenderDrawPoint(m_renderer, (int) x, (int) y) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

int Renderer::width() const
{
    return m_width;
}

int Renderer::height() const
{
    return m_height;
}

}
