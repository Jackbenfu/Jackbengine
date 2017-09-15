//
// mouseListenerComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 07/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_LISTENER_COMPONENT_2_H__
#define __MOUSE_LISTENER_COMPONENT_2_H__

#include <functional>
#include "component/component2.hpp"

namespace Jackbengine {

using MouseCallback2 = std::function<void()>;

enum MouseEvent2
{
    MouseEvent_LeftClick2 = 1,
    MouseEvent_MiddleClick2 = 2,
    MouseEvent_RightClick2 = 4,
    MouseEvent_Hover2 = 8,
    MouseEvent_Enter2 = 16,
    MouseEvent_Exit2 = 32,
};

class MouseListenerComponent2 : public Component2
{
    friend class MouseEventTriggerSystem2;

    DISALLOW_COPY_AND_MOVE(MouseListenerComponent2)

public:
    MouseListenerComponent2() = default;
    ~MouseListenerComponent2() override = default;

    void onLeftClick(MouseCallback2 callback);
    void onLeftDown(MouseCallback2 callback);

    void onMiddleClick(MouseCallback2 callback);
    void onMiddleDown(MouseCallback2 callback);

    void onRightClick(MouseCallback2 callback);
    void onRightDown(MouseCallback2 callback);

    void onHover(MouseCallback2 callback);
    void onEnter(MouseCallback2 callback);
    void onExit(MouseCallback2 callback);

    bool leftClick();
    bool middleClick();
    bool rightClick();
    bool hover() const;
    bool enter() const;
    bool exit() const;

private:
    MouseCallback2 m_onLeftClick {nullptr};
    void callLeftClick();

    MouseCallback2 m_onLeftDown {nullptr};
    void callLeftDown() const;

    MouseCallback2 m_onMiddleClick {nullptr};
    void callMiddleClick();

    MouseCallback2 m_onMiddleDown {nullptr};
    void callMiddleDown() const;

    MouseCallback2 m_onRightClick {nullptr};
    void callRightClick();

    MouseCallback2 m_onRightDown {nullptr};
    void callRightDown() const;

    MouseCallback2 m_onHover {nullptr};
    void callOnHover();

    MouseCallback2 m_onEnter {nullptr};
    void callOnEnter();

    MouseCallback2 m_onExit {nullptr};
    void callOnExit();

    uint m_events {0};

    void addEvent(MouseEvent2 event);
    void removeEvent(MouseEvent2 event);
    bool hasEvent(MouseEvent2 event) const;
    bool hasAndRemoveEvent(MouseEvent2 event);
};

using MouseListener = MouseListenerComponent2;

} // namespace Jackbengine

#endif // __MOUSE_LISTENER_COMPONENT_2_H__
