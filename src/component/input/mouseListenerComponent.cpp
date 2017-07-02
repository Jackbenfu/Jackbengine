//
// mouseListenerComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 28/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "mouseListenerComponent.hpp"

using namespace Jackbengine;

MouseListenerComponent::MouseListenerComponent(Scene *scene)
    : m_scene(scene)
{
    // Nothing
}

MouseListenerComponent::~MouseListenerComponent() = default;

void MouseListenerComponent::onLeftClick(MouseCallback callback, void *data)
{
    m_onLeftClick = callback;
    m_onLeftClickData = data;
}

void MouseListenerComponent::callLeftClick()
{
    addEvent(MouseEvent_LeftClick);
    if (m_onLeftClick)
    {
        m_onLeftClick(m_scene, m_onLeftClickData);
    }
}

void MouseListenerComponent::onLeftDown(MouseCallback callback, void *data)
{
    m_onLeftDown = callback;
    m_onLeftDownData = data;
}

void MouseListenerComponent::callLeftDown() const
{
    if (m_onLeftDown)
    {
        m_onLeftDown(m_scene, m_onLeftDownData);
    }
}

void MouseListenerComponent::onMiddleClick(MouseCallback callback, void *data)
{
    m_onMiddleClick = callback;
    m_onMiddleClickData = data;
}

void MouseListenerComponent::callMiddleClick()
{
    addEvent(MouseEvent_MiddleClick);
    if (m_onMiddleClick)
    {
        m_onMiddleClick(m_scene, m_onMiddleClickData);
    }
}

void MouseListenerComponent::onMiddleDown(MouseCallback callback, void *data)
{
    m_onMiddleDown = callback;
    m_onMiddleDownData = data;
}

void MouseListenerComponent::callMiddleDown() const
{
    if (m_onMiddleDown)
    {
        m_onMiddleDown(m_scene, m_onMiddleDownData);
    }
}

void MouseListenerComponent::onRightClick(MouseCallback callback, void *data)
{
    m_onRightClick = callback;
    m_onRightClickData = data;
}

void MouseListenerComponent::callRightClick()
{
    addEvent(MouseEvent_RightClick);
    if (m_onRightClick)
    {
        m_onRightClick(m_scene, m_onRightClickData);
    }
}

void MouseListenerComponent::onRightDown(MouseCallback callback, void *data)
{
    m_onRightDown = callback;
    m_onRightDownData = data;
}

void MouseListenerComponent::callRightDown() const
{
    if (m_onRightDown)
    {
        m_onRightDown(m_scene, m_onRightDownData);
    }
}

void MouseListenerComponent::onHover(MouseCallback callback, void *data)
{
    m_onHover = callback;
    m_onHoverData = data;
}

void MouseListenerComponent::callOnHover()
{
    addEvent(MouseEvent_Hover);
    if (m_onHover)
    {
        m_onHover(m_scene, m_onHoverData);
    }
}

void MouseListenerComponent::onEnter(MouseCallback callback, void *data)
{
    m_onEnter = callback;
    m_onEnterData = data;
}

void MouseListenerComponent::callOnEnter()
{
    addEvent(MouseEvent_Enter);
    if (m_onEnter)
    {
        m_onEnter(m_scene, m_onEnterData);
    }
}

void MouseListenerComponent::onExit(MouseCallback callback, void *data)
{
    m_onExit = callback;
    m_onExitData = data;
}

void MouseListenerComponent::callOnExit()
{
    addEvent(MouseEvent_Exit);
    if (m_onExit)
    {
        m_onExit(m_scene, m_onExitData);
    }
}

bool MouseListenerComponent::leftClick()
{
    return hasAndRemoveEvent(MouseEvent_LeftClick);
}

bool MouseListenerComponent::middleClick()
{
    return hasAndRemoveEvent(MouseEvent_MiddleClick);
}

bool MouseListenerComponent::rightClick()
{
    return hasAndRemoveEvent(MouseEvent_RightClick);
}

bool MouseListenerComponent::hover() const
{
    return hasEvent(MouseEvent_Hover);
}

bool MouseListenerComponent::enter() const
{
    return hasEvent(MouseEvent_Enter);
}

bool MouseListenerComponent::exit() const
{
    return hasEvent(MouseEvent_Exit);
}

void MouseListenerComponent::addEvent(MouseEvent event)
{
    m_events |= event;
}

void MouseListenerComponent::removeEvent(MouseEvent event)
{
    m_events &= ~event;
}

bool MouseListenerComponent::hasAndRemoveEvent(MouseEvent event)
{
    bool result = hasEvent(event);
    removeEvent(event);

    return result;
}

bool MouseListenerComponent::hasEvent(MouseEvent event) const
{
    return event == (m_events & event);
}
