//
// window.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "window.h"
#include "windowImpl.h"

Window::Window()
{
}

Window::~Window()
{
}

Window* Window::create()
{
    return new WindowImpl();
}
