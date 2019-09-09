//
// mouseDownEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 22/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_DOWN_EVENT_H__
#define __MOUSE_DOWN_EVENT_H__

#include "mouseEvent.h"
#include "core/event/mouseButton.h"

namespace Jackbengine {

class MouseDownEvent : public details::MouseEvent
{
public:
    EVENT_CLASS_TYPE(EventType::MouseDown)

    MouseDownEvent(int x, int y, MouseButton button, int repeat)
        : MouseEvent {x, y},
          m_button {button},
          m_repeat {repeat}
    {}

    [[nodiscard]] std::string toString() const override;

private:
    MouseButton m_button;
    int m_repeat;
};

}

#endif // __MOUSE_DOWN_EVENT_H__
