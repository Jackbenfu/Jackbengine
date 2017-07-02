//
// cursorImpl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_IMPL_H__
#define __CURSOR_IMPL_H__

#include "cursor.hpp"
#include "platform.hpp"

namespace Jackbengine {

class CursorImpl : public Cursor
{
    friend class Cursor;

public:
    ~CursorImpl() override;

    void setCursor(CursorType cursor) override;

private:
    CursorImpl();

    SDL_Cursor *m_cursor = nullptr;
};

} // namespace Jackbengine

#endif // __CURSOR_IMPL_H__
