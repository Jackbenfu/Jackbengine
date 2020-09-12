//
// cursor.h
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
//

#ifndef __CURSOR_H__
#define __CURSOR_H__

typedef struct SDL_Cursor SDL_Cursor;

namespace Jackbengine::details {

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

    static void showCursor(bool visible);

private:
    SDL_Cursor* m_cursor {nullptr};
};

}

#endif // __CURSOR_H__
