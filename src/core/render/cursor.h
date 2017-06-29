//
// cursor.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_H__
#define __CURSOR_H__

#include "common.h"

NS_BEGIN_JKB

enum class CursorType
{
    Default,
    Hand
};

class Cursor
{
public:
    virtual ~Cursor();

    virtual void setCursor(CursorType cursor) = 0;

    static Cursor* create();

protected:
    Cursor();
};

NS_END_JKB

#endif // __CURSOR_H__
