//
// input.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "input.hpp"
#include "inputImpl.hpp"

using namespace Jackbengine;

Input::Input() = default;

Input::~Input() = default;

Input* Input::create()
{
    return new InputImpl();
}
