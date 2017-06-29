//
// cursorImpl.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_IMPL_H__
#define __CURSOR_IMPL_H__

#include "cursor.h"
#include "platform.h"

NS_BEGIN_JKB

class CursorImpl : public Cursor
{
    friend class Cursor;

public:
    ~CursorImpl();

    void setCursor(CursorType cursor) override;

private:
    CursorImpl();

    SDL_Cursor *m_cursor = nullptr;
};

NS_END_JKB

#endif // __CURSOR_IMPL_H__
