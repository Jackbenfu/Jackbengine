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
{
    // Nothing
}

Window2::~Window2() = default;

int Window2::getWidth() const
{
    return m_impl->getWidth();
}

int Window2::getHeight() const
{
    return m_impl->getHeight();
}

void* Window2::getInternalObject() const
{
    return m_impl->getInternalObject();
}
