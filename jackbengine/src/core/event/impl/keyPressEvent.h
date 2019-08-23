//
// keyPressEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 22/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __KEY_PRESS_EVENT_H__
#define __KEY_PRESS_EVENT_H__

#include "keyEvent.h"

namespace Jackbengine {

class KeyPressEvent : public KeyEvent
{
public:
    EVENT_CLASS_TYPE(EventType::KeyPress)

    KeyPressEvent(KeyboardKey physicalKey, KeyboardKey virtualKey)
        : KeyEvent {physicalKey, virtualKey}
    {}

    [[nodiscard]] std::string toString() const override
    {
        return fmt::format("KeyPressEvent: {}", keys());
    }
};

}

#endif // __KEY_PRESS_EVENT_H__
