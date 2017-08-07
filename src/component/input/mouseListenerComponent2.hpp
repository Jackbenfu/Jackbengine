//
// mouseListenerComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 07/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_LISTENER_COMPONENT_2_H__
#define __MOUSE_LISTENER_COMPONENT_2_H__

#include "component/component2.hpp"

namespace Jackbengine {

using MouseCallback2 = void(*)(void *data);

class MouseListenerComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(MouseListenerComponent2)

public:
    MouseListenerComponent2() = default;
    ~MouseListenerComponent2() override = default;

    void onLeftClick(MouseCallback2 callback, void *data = nullptr);
    void onLeftDown(MouseCallback2 callback, void *data = nullptr);

    void onMiddleClick(MouseCallback2 callback, void *data = nullptr);
    void onMiddleDown(MouseCallback2 callback, void *data = nullptr);

    void onRightClick(MouseCallback2 callback, void *data = nullptr);
    void onRightDown(MouseCallback2 callback, void *data = nullptr);

    void onHover(MouseCallback2 callback, void *data = nullptr);
    void onEnter(MouseCallback2 callback, void *data = nullptr);
    void onExit(MouseCallback2 callback, void *data = nullptr);

    bool leftClick();
    bool middleClick();
    bool rightClick();
    bool hover() const;
    bool enter() const;
    bool exit() const;

private:
    MouseCallback2 m_onLeftClick {nullptr};
    void *m_onLeftClickData {nullptr};
    void callLeftClick();

    MouseCallback2 m_onLeftDown {nullptr};
    void *m_onLeftDownData {nullptr};
    void callLeftDown() const;

    MouseCallback2 m_onMiddleClick {nullptr};
    void *m_onMiddleClickData {nullptr};
    void callMiddleClick();

    MouseCallback2 m_onMiddleDown {nullptr};
    void *m_onMiddleDownData {nullptr};
    void callMiddleDown() const;

    MouseCallback2 m_onRightClick {nullptr};
    void *m_onRightClickData {nullptr};
    void callRightClick();

    MouseCallback2 m_onRightDown {nullptr};
    void *m_onRightDownData {nullptr};
    void callRightDown() const;

    MouseCallback2 m_onHover {nullptr};
    void *m_onHoverData {nullptr};
    void callOnHover();

    MouseCallback2 m_onEnter {nullptr};
    void *m_onEnterData {nullptr};
    void callOnEnter();

    MouseCallback2 m_onExit {nullptr};
    void *m_onExitData {nullptr};
    void callOnExit();

    uint m_events {0};

    enum MouseEvent2
    {
        MouseEvent_LeftClick = 1,
        MouseEvent_MiddleClick = 2,
        MouseEvent_RightClick = 4,
        MouseEvent_Hover = 8,
        MouseEvent_Enter = 16,
        MouseEvent_Exit = 32,
    };

    void addEvent(MouseEvent2 event);
    void removeEvent(MouseEvent2 event);
    bool hasEvent(MouseEvent2 event) const;
    bool hasAndRemoveEvent(MouseEvent2 event);
};

} // namespace Jackbengine

#endif // __MOUSE_LISTENER_COMPONENT_2_H__
