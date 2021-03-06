//
// cursor.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "cursor.hpp"

namespace Jackbengine {

Cursor::~Cursor()
{
    SDL_FreeCursor(m_cursor);
}

void Cursor::setCursor(CursorType cursor)
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

    if (nullptr != m_cursor)
    {
        SDL_FreeCursor(m_cursor);
    }

    m_cursor = SDL_CreateSystemCursor(id);
    SDL_SetCursor(m_cursor);
}

void Cursor::showCursor(bool visible)
{
    SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
}

}
