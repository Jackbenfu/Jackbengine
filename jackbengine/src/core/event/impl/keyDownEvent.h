//
// keyDownEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __KEY_DOWN_EVENT_H__
#define __KEY_DOWN_EVENT_H__

#include "keyEvent.h"

namespace Jackbengine {

class KeyDownEvent : public KeyEvent
{
public:
    EVENT_CLASS_TYPE(EventType::KeyDown)

    KeyDownEvent(KeyboardKey physicalKey, KeyboardKey virtualKey, int repeat)
        : KeyEvent {physicalKey, virtualKey},
          m_repeat {repeat}
    {}

    [[nodiscard]] std::string toString() const override
    {
        return fmt::format("KeyDownEvent: {}, repeat={}", keys(), m_repeat);
    }

private:
    int m_repeat;
};

}

#endif // __KEY_DOWN_EVENT_H__
