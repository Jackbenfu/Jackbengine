//
// font.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "font.h"
#include "fontImpl.h"

Font::Font()
{
}

Font::~Font()
{
}

Font* Font::create()
{
    return new FontImpl();
}
