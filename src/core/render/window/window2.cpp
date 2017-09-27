//
// window2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "window2.hpp"
#include "window2.impl.hpp"

using namespace Jackbengine;

Window2::Window2(const std::string& title, int width, int height, bool fullscreen)
    : m_impl {std::make_unique<Impl>(title, width, height, fullscreen)}
{ }

Window2::~Window2() = default;

int Window2::width() const
{
    return m_impl->width();
}

int Window2::height() const
{
    return m_impl->height();
}

void* Window2::internalObject() const
{
    return m_impl->internalObject();
}
