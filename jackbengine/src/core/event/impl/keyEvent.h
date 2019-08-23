//
// keyEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 22/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __KEY_EVENT_H__
#define __KEY_EVENT_H__

#include "core/event/event.h"

namespace Jackbengine {

class KeyEvent : public Event
{
public:
    KeyEvent(KeyboardKey physicalKey, KeyboardKey virtualKey)
        : m_physicalKey {physicalKey}, m_virtualKey {virtualKey}
    {}

    [[nodiscard]] inline KeyboardKey physicalKey() const
    {
        return m_physicalKey;
    }

    [[nodiscard]] inline KeyboardKey virtualKey() const
    {
        return m_virtualKey;
    }

protected:
    [[nodiscard]] std::string keys() const
    {
        return fmt::format("physicalKey={}, virtualKey={}", (int) physicalKey(), (int) virtualKey());
    }

private:
    KeyboardKey m_physicalKey;
    KeyboardKey m_virtualKey;
};

}

#endif // __KEY_EVENT_H__
