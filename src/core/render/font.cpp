//
// font.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "font.hpp"
#include "fontImpl.hpp"

using namespace Jackbengine;

Font::Font() = default;

Font::~Font() = default;

Font* Font::create()
{
    return new FontImpl();
}
