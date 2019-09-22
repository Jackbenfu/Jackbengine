//
// keyUpEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __KEY_UP_EVENT_H__
#define __KEY_UP_EVENT_H__

#include "keyEvent.h"

namespace Jackbengine {

class KeyUpEvent : public KeyEvent
{
public:
    EVENT_CLASS_TYPE(EventType::KeyUp)

    KeyUpEvent(KeyboardKey physicalKey, KeyboardKey virtualKey)
        : KeyEvent {physicalKey, virtualKey}
    {}

    [[nodiscard]] std::string toString() const override;
};

}

#endif // __KEY_UP_EVENT_H__
