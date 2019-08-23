//
// mouseClickEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 23/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_CLICK_EVENT_H__
#define __MOUSE_CLICK_EVENT_H__

#include "mouseEvent.h"
#include "core/input/mouseButton.h"

namespace Jackbengine {

class MouseClickEvent : public MouseEvent
{
public:
    EVENT_CLASS_TYPE(EventType::MouseClick)

    MouseClickEvent(int x, int y, MouseButton button)
        : MouseEvent {x, y},
          m_button {button}
    {}

    [[nodiscard]] std::string toString() const override
    {
        return fmt::format("MouseClickEvent: x={}, y={}, button={}", x(), y(), (int) m_button);
    }

private:
    MouseButton m_button;
};

}

#endif // __MOUSE_CLICK_EVENT_H__
