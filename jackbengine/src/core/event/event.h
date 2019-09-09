//
// event.h
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

namespace Jackbengine {

enum class EventType
{
    ApplicationClose,

    KeyDown,
    KeyUp,

    MouseDown,
    MouseUp,
    MouseMotion,
};

#define EVENT_CLASS_TYPE(type)  inline static EventType staticType() { return type; }                           \
                                inline virtual EventType eventType() const override { return staticType(); }

#define BIND_EVENT_CALLBACK(func) std::bind(&Application::func, this, std::placeholders::_1)

namespace details {

class Event
{
public:
    bool handled {false};

    [[nodiscard]] virtual EventType eventType() const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};

class EventDispatcher
{
public:
    explicit EventDispatcher(Event &e)
        : m_event {e}
    {}

    template<typename T>
    bool dispatch(std::function<bool(T &)> callback)
    {
        if (m_event.eventType() == T::staticType())
        {
            m_event.handled = (callback(*(T *) &m_event));
            return true;
        }

        return false;
    }

private:
    Event &m_event;
};

}
}

#endif // __EVENT_H__
