//
// cursor.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_IMPL_H__
#define __CURSOR_IMPL_H__

#include "core/sdl/sdl.hpp"
#include "cursor.hpp"

namespace Jackbengine {

class Cursor::Impl
{
public:
    Impl() = default;
    ~Impl();

    void setCursor(CursorType cursor);

    void showCursor(bool visible);

private:
    SDL_Cursor *m_cursor {nullptr};
};

}

#endif // __CURSOR_IMPL_H__
