//
// cursor.h
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_H__
#define __CURSOR_H__

#include "core/sdl/sdl.h"

namespace Jackbengine {

enum class CursorType
{
    Default,
    Hand,
};

class Cursor
{
public:
    Cursor() = default;
    ~Cursor();

    void setCursor(CursorType cursor);

    void showCursor(bool visible);

private:
    SDL_Cursor *m_cursor {nullptr};
};

}

#endif // __CURSOR_H__
