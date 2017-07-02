//
// cursorImpl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "cursorImpl.hpp"

using namespace Jackbengine;

CursorImpl::CursorImpl() = default;

CursorImpl::~CursorImpl()
{
    SDL_FreeCursor(m_cursor);
}

void CursorImpl::setCursor(CursorType cursor)
{
    SDL_SystemCursor id;

    switch (cursor)
    {
        case CursorType::Hand:
            id = SDL_SYSTEM_CURSOR_HAND;
            break;

        case CursorType::Default:
            id = SDL_SYSTEM_CURSOR_ARROW;
            break;
    }

    if (nullptr == m_cursor)
    {
        SDL_FreeCursor(m_cursor);
    }

    m_cursor = SDL_CreateSystemCursor(id);
    SDL_SetCursor(m_cursor);
}
