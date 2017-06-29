//
// cursor.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "cursor.h"
#include "cursorImpl.h"

Cursor::Cursor()
{
}

Cursor::~Cursor()
{
}

Cursor* Cursor::create()
{
    return new CursorImpl();
}
