//
//  mouseListenerComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 28/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_LISTENER_COMPONENT_H__
#define __MOUSE_LISTENER_COMPONENT_H__

#include "component/component.h"
#include "common.h"

NS_BEGIN_JKB

using MouseCallback = void(*)(void *data);

enum MouseEvent
{
    MouseEvent_LeftClick = 1,
    MouseEvent_MiddleClick = 2,
    MouseEvent_RightClick = 4,
    MouseEvent_Hover = 8,
    MouseEvent_Enter = 16,
    MouseEvent_Exit = 32
};

class MouseListenerComponent :
    public Component,
    public TypedObject<MouseListenerComponent>
{
    friend class MouseEventTriggerSystem;

public:
    MouseListenerComponent();
    ~MouseListenerComponent();

    void onLeftClick(MouseCallback callback, void *data = nullptr);
    void onLeftDown(MouseCallback callback, void *data = nullptr);

    void onMiddleClick(MouseCallback callback, void *data = nullptr);
    void onMiddleDown(MouseCallback callback, void *data = nullptr);

    void onRightClick(MouseCallback callback, void *data = nullptr);
    void onRightDown(MouseCallback callback, void *data = nullptr);

    void onHover(MouseCallback callback, void *data = nullptr);
    void onEnter(MouseCallback callback, void *data = nullptr);
    void onExit(MouseCallback callback, void *data = nullptr);

    bool leftClick();
    bool middleClick();
    bool rightClick();
    bool hover() const;
    bool enter() const;
    bool exit() const;

private:
    MouseCallback m_onLeftClick = nullptr;
    void *m_onLeftClickData = nullptr;
    void callLeftClick();

    MouseCallback m_onLeftDown = nullptr;
    void *m_onLeftDownData = nullptr;
    void callLeftDown() const;

    MouseCallback m_onMiddleClick = nullptr;
    void *m_onMiddleClickData = nullptr;
    void callMiddleClick();

    MouseCallback _onMiddleDown = nullptr;
    void *_onMiddleDownData = nullptr;
    void _callMiddleDown() const;

    MouseCallback m_onRightClick = nullptr;
    void *m_onRightClickData = nullptr;
    void callRightClick();

    MouseCallback m_onRightDown = nullptr;
    void *m_onRightDownData = nullptr;
    void callRightDown() const;

    MouseCallback m_onHover = nullptr;
    void *m_onHoverData = nullptr;
    void callOnHover();

    MouseCallback m_onEnter = nullptr;
    void *m_onEnterData = nullptr;
    void callOnEnter();

    MouseCallback m_onExit = nullptr;
    void *m_onExitData = nullptr;
    void callOnExit();

    uint m_events = 0;
    void addEvent(MouseEvent event);
    void removeEvent(MouseEvent event);
    bool hasEvent(MouseEvent event) const;
    bool hasAndRemoveEvent(MouseEvent event);
    void resetEvents();
};

NS_END_JKB

#endif // __MOUSE_LISTENER_COMPONENT_H__
