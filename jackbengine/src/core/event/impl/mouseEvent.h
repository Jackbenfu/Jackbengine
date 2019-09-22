//
// mouseEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 22/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_EVENT_H__
#define __MOUSE_EVENT_H__

#include "core/event/event.h"

namespace Jackbengine {

class MouseEvent : public Event
{
public:
    MouseEvent(int x, int y)
        : m_x {x}, m_y {y}
    {}

    [[nodiscard]] inline int x() const
    {
        return m_x;
    }

    [[nodiscard]] inline int y() const
    {
        return m_y;
    }

private:
    int m_x;
    int m_y;
};

}

#endif // __MOUSE_EVENT_H__
