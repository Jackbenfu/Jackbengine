//
// event.h
// jackbengine
//
// Created by Damien Bendejacq on 19/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __EVENT_H__
#define __EVENT_H__

#include "pch.h"

namespace Jackbengine {

enum class EventType
{
    ApplicationClosed,
};

#define EVENT_CLASS_TYPE(type)  static EventType staticType() { return type; }                          \
                                virtual EventType eventType() const override { return staticType(); }   \
                                virtual const char* name() const override { return #type; }

#define BIND_EVENT_FUNC(func) std::bind(&Application::func, this, std::placeholders::_1)

class Event
{
public:
    bool handled {false};

    [[nodiscard]] virtual EventType eventType() const = 0;
    [[nodiscard]] virtual const char *name() const = 0;
};

class EventDispatcher
{
    template<typename T>
    using EventFunc = std::function<bool(const T &)>;

public:
    explicit EventDispatcher(Event &e)
        : m_event {e}
    {}

    template<typename T>
    bool dispatch(EventFunc<T> func)
    {
        if (m_event.eventType() == T::staticType())
        {
            m_event.handled = (func(*(T *) &m_event));
            return true;
        }

        return false;
    }

private:
    Event &m_event;
};

}

#endif // __EVENT_H__
