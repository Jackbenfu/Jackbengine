//
// mouseListenerComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 07/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "mouseListenerComponent2.hpp"

using namespace Jackbengine;

void MouseListenerComponent2::onLeftClick(MouseCallback2 callback, void *data)
{
    m_onLeftClick = callback;
    m_onLeftClickData = data;
}

void MouseListenerComponent2::callLeftClick()
{
    addEvent(MouseEvent2::MouseEvent_LeftClick);
    if (nullptr != m_onLeftClick)
    {
        m_onLeftClick(m_onLeftClickData);
    }
}

void MouseListenerComponent2::onLeftDown(MouseCallback2 callback, void *data)
{
    m_onLeftDown = callback;
    m_onLeftDownData = data;
}

void MouseListenerComponent2::callLeftDown() const
{
    if (nullptr != m_onLeftDown)
    {
        m_onLeftDown(m_onLeftDownData);
    }
}

void MouseListenerComponent2::onMiddleClick(MouseCallback2 callback, void *data)
{
    m_onMiddleClick = callback;
    m_onMiddleClickData = data;
}

void MouseListenerComponent2::callMiddleClick()
{
    addEvent(MouseEvent2::MouseEvent_MiddleClick);
    if (nullptr != m_onMiddleClick)
    {
        m_onMiddleClick(m_onMiddleClickData);
    }
}

void MouseListenerComponent2::onMiddleDown(MouseCallback2 callback, void *data)
{
    m_onMiddleDown = callback;
    m_onMiddleDownData = data;
}

void MouseListenerComponent2::callMiddleDown() const
{
    if (nullptr != m_onMiddleDown)
    {
        m_onMiddleDown(m_onMiddleDownData);
    }
}

void MouseListenerComponent2::onRightClick(MouseCallback2 callback, void *data)
{
    m_onRightClick = callback;
    m_onRightClickData = data;
}

void MouseListenerComponent2::callRightClick()
{
    addEvent(MouseEvent2::MouseEvent_RightClick);
    if (nullptr != m_onRightClick)
    {
        m_onRightClick(m_onRightClickData);
    }
}

void MouseListenerComponent2::onRightDown(MouseCallback2 callback, void *data)
{
    m_onRightDown = callback;
    m_onRightDownData = data;
}

void MouseListenerComponent2::callRightDown() const
{
    if (nullptr != m_onRightDown)
    {
        m_onRightDown(m_onRightDownData);
    }
}

void MouseListenerComponent2::onHover(MouseCallback2 callback, void *data)
{
    m_onHover = callback;
    m_onHoverData = data;
}

void MouseListenerComponent2::callOnHover()
{
    addEvent(MouseEvent2::MouseEvent_Hover);
    if (nullptr != m_onHover)
    {
        m_onHover(m_onHoverData);
    }
}

void MouseListenerComponent2::onEnter(MouseCallback2 callback, void *data)
{
    m_onEnter = callback;
    m_onEnterData = data;
}

void MouseListenerComponent2::callOnEnter()
{
    addEvent(MouseEvent2::MouseEvent_Enter);
    if (nullptr != m_onEnter)
    {
        m_onEnter(m_onEnterData);
    }
}

void MouseListenerComponent2::onExit(MouseCallback2 callback, void *data)
{
    m_onExit = callback;
    m_onExitData = data;
}

void MouseListenerComponent2::callOnExit()
{
    addEvent(MouseEvent2::MouseEvent_Exit);
    if (nullptr != m_onExit)
    {
        m_onExit(m_onExitData);
    }
}

bool MouseListenerComponent2::leftClick()
{
    return hasAndRemoveEvent(MouseEvent2::MouseEvent_LeftClick);
}

bool MouseListenerComponent2::middleClick()
{
    return hasAndRemoveEvent(MouseEvent2::MouseEvent_MiddleClick);
}

bool MouseListenerComponent2::rightClick()
{
    return hasAndRemoveEvent(MouseEvent2::MouseEvent_RightClick);
}

bool MouseListenerComponent2::hover() const
{
    return hasEvent(MouseEvent2::MouseEvent_Hover);
}

bool MouseListenerComponent2::enter() const
{
    return hasEvent(MouseEvent2::MouseEvent_Enter);
}

bool MouseListenerComponent2::exit() const
{
    return hasEvent(MouseEvent2::MouseEvent_Exit);
}

void MouseListenerComponent2::addEvent(MouseEvent2 event)
{
    m_events |= event;
}

void MouseListenerComponent2::removeEvent(MouseEvent2 event)
{
    m_events &= ~event;
}

bool MouseListenerComponent2::hasAndRemoveEvent(MouseEvent2 event)
{
    bool result = hasEvent(event);
    removeEvent(event);

    return result;
}

bool MouseListenerComponent2::hasEvent(MouseEvent2 event) const
{
    return event == (m_events & event);
}
