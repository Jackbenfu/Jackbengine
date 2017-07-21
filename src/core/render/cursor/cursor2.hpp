//
// cursor2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __CURSOR_2_H__
#define __CURSOR_2_H__

#include <memory>
#include "common.hpp"

namespace Jackbengine {

enum class CursorType2
{
    Default,
    Hand,
};

class Cursor2
{
    DISALLOW_COPY_AND_MOVE(Cursor2)

public:
    Cursor2();
    ~Cursor2();

    void setCursor(CursorType2 cursor);

    void showCursor(bool visible);

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __CURSOR_2_H__
