//
// window.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "window.hpp"
#include "windowImpl.hpp"

using namespace Jackbengine;

Window::Window() = default;

Window::~Window() = default;

Window* Window::create()
{
    return new WindowImpl();
}
