//
// mouseListenerComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 07/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "mouseListenerComponent2.hpp"

using namespace Jackbengine;

void MouseListenerComponent2::onLeftClick(MouseCallback2 callback)
{
    m_onLeftClick = std::move(callback);
}

void MouseListenerComponent2::callLeftClick()
{
    addEvent(MouseEvent2::MouseEvent_LeftClick2);
    if (nullptr != m_onLeftClick)
    {
        m_onLeftClick();
    }
}

void MouseListenerComponent2::onLeftDown(MouseCallback2 callback)
{
    m_onLeftDown = std::move(callback);
}

void MouseListenerComponent2::callLeftDown() const
{
    if (nullptr != m_onLeftDown)
    {
        m_onLeftDown();
    }
}

void MouseListenerComponent2::onMiddleClick(MouseCallback2 callback)
{
    m_onMiddleClick = std::move(callback);
}

void MouseListenerComponent2::callMiddleClick()
{
    addEvent(MouseEvent2::MouseEvent_MiddleClick2);
    if (nullptr != m_onMiddleClick)
    {
        m_onMiddleClick();
    }
}

void MouseListenerComponent2::onMiddleDown(MouseCallback2 callback)
{
    m_onMiddleDown = std::move(callback);
}

void MouseListenerComponent2::callMiddleDown() const
{
    if (nullptr != m_onMiddleDown)
    {
        m_onMiddleDown();
    }
}

void MouseListenerComponent2::onRightClick(MouseCallback2 callback)
{
    m_onRightClick = std::move(callback);
}

void MouseListenerComponent2::callRightClick()
{
    addEvent(MouseEvent2::MouseEvent_RightClick2);
    if (nullptr != m_onRightClick)
    {
        m_onRightClick();
    }
}

void MouseListenerComponent2::onRightDown(MouseCallback2 callback)
{
    m_onRightDown = std::move(callback);
}

void MouseListenerComponent2::callRightDown() const
{
    if (nullptr != m_onRightDown)
    {
        m_onRightDown();
    }
}

void MouseListenerComponent2::onHover(MouseCallback2 callback)
{
    m_onHover = std::move(callback);
}

void MouseListenerComponent2::callOnHover()
{
    addEvent(MouseEvent2::MouseEvent_Hover2);
    if (nullptr != m_onHover)
    {
        m_onHover();
    }
}

void MouseListenerComponent2::onEnter(MouseCallback2 callback)
{
    m_onEnter = std::move(callback);
}

void MouseListenerComponent2::callOnEnter()
{
    addEvent(MouseEvent2::MouseEvent_Enter2);
    if (nullptr != m_onEnter)
    {
        m_onEnter();
    }
}

void MouseListenerComponent2::onExit(MouseCallback2 callback)
{
    m_onExit = std::move(callback);
}

void MouseListenerComponent2::callOnExit()
{
    addEvent(MouseEvent2::MouseEvent_Exit2);
    if (nullptr != m_onExit)
    {
        m_onExit();
    }
}

bool MouseListenerComponent2::leftClick()
{
    return hasAndRemoveEvent(MouseEvent2::MouseEvent_LeftClick2);
}

bool MouseListenerComponent2::middleClick()
{
    return hasAndRemoveEvent(MouseEvent2::MouseEvent_MiddleClick2);
}

bool MouseListenerComponent2::rightClick()
{
    return hasAndRemoveEvent(MouseEvent2::MouseEvent_RightClick2);
}

bool MouseListenerComponent2::hover() const
{
    return hasEvent(MouseEvent2::MouseEvent_Hover2);
}

bool MouseListenerComponent2::enter() const
{
    return hasEvent(MouseEvent2::MouseEvent_Enter2);
}

bool MouseListenerComponent2::exit() const
{
    return hasEvent(MouseEvent2::MouseEvent_Exit2);
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
