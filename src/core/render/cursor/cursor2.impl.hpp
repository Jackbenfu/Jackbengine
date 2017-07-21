//
// cursor2.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_2_IMPL_H__
#define __CURSOR_2_IMPL_H__

#include "cursor2.hpp"
#include "platform.hpp"

namespace Jackbengine {

class Cursor2::Impl
{
public:
    Impl() = default;
    ~Impl();

    void setCursor(CursorType2 cursor);

    void showCursor(bool visible);

private:
    SDL_Cursor *m_cursor {nullptr};
};

} // namespace Jackbengine

#endif // __CURSOR_2_IMPL_H__
