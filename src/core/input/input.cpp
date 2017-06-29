//
// input.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "input.h"
#include "inputImpl.h"

Input::Input()
{
}

Input::~Input()
{
}

Input* Input::create()
{
    return new InputImpl();
}
