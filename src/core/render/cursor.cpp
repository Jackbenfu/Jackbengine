//
// cursor.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "cursor.hpp"
#include "cursorImpl.hpp"

using namespace Jackbengine;

Cursor::Cursor() = default;

Cursor::~Cursor() = default;

Cursor* Cursor::create()
{
    return new CursorImpl();
}
