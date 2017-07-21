//
// renderer2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "renderer2.hpp"
#include "renderer2.impl.hpp"

using namespace Jackbengine;

Renderer2::Renderer2(const Window2& window)
    : m_impl {std::make_unique<Impl>(window)}
{
    // Nothing
}

Renderer2::~Renderer2() = default;

void Renderer2::clear()
{
    m_impl->clear();
}

void Renderer2::present()
{
    m_impl->present();
}

void Renderer2::setClearColor(Color color)
{
    m_impl->setClearColor(color);
}

void Renderer2::setRenderColor(Color color)
{
    m_impl->setRenderColor(color);
}

void Renderer2::renderTexture(int x, int y, const Texture2& texture)
{
    m_impl->renderTexture(x, y, texture);
}

void Renderer2::renderTexture(int x, int y, const Texture2& texture, double angle)
{
    m_impl->renderTexture(x, y, texture, angle);
}

void Renderer2::renderLine(float x1, float y1, float x2, float y2, Color color)
{
    m_impl->renderLine(x1, y1, x2, y2, color);
}

void Renderer2::renderPoint(float x, float y, Color color)
{
    m_impl->renderPoint(x, y, color);
}

void* Renderer2::getInternalObject() const
{
    return m_impl->getInternalObject();
}