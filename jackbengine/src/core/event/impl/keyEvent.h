//
// keyEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 22/08/2019.
//

#ifndef __KEY_EVENT_H__
#define __KEY_EVENT_H__

#include "core/event/event.h"
#include "core/event/keyboardKey.h"

namespace Jackbengine {

class KeyEvent : public Event
{
protected:
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
    [[nodiscard]] std::string keys() const;

private:
    KeyboardKey m_physicalKey;
    KeyboardKey m_virtualKey;
};

}

#endif // __KEY_EVENT_H__
