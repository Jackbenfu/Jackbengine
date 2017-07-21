//
// cursor2.impl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "cursor2.impl.hpp"

using namespace Jackbengine;

Cursor2::Impl::~Impl()
{
    SDL_FreeCursor(m_cursor);
}

void Cursor2::Impl::setCursor(CursorType2 cursor)
{
    SDL_SystemCursor id;

    switch (cursor)
    {
        case CursorType2::Hand:
            id = SDL_SYSTEM_CURSOR_HAND;
            break;

        case CursorType2::Default:
            id = SDL_SYSTEM_CURSOR_ARROW;
            break;
    }

    if (nullptr != m_cursor)
    {
        SDL_FreeCursor(m_cursor);
    }

    m_cursor = SDL_CreateSystemCursor(id);
    SDL_SetCursor(m_cursor);
}

void Cursor2::Impl::showCursor(bool visible)
{
    SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
}
