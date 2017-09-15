//
// mouseEventTriggerSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "mouseEventTriggerSystem2.hpp"
#include "component/layout/containerComponent2.hpp"
#include "component/input/mouseListenerComponent2.hpp"
#include "component/layout/zOrderComponent2.hpp"

using namespace Jackbengine;

MouseEventTriggerSystem2::MouseEventTriggerSystem2(const Input2& input)
    : m_input {input}
{
    // Nothing
}

void MouseEventTriggerSystem2::setBubbling(bool active)
{
    m_bubbling = active;
}

void MouseEventTriggerSystem2::frame(float delta)
{
    UNUSED(delta);

    MouseListenerComponent2 *clickedMouseListener {nullptr};
    auto maxZOrder = 0;

    for (const auto& entity : m_entities)
    {
        const auto components = entity.second;

        const auto& container = components->get<ContainerComponent2>();
        auto& mouseListener = components->get<MouseListenerComponent2>();

        auto hadEnter = mouseListener.hasEvent(MouseEvent_Enter2);
        auto mousePos = m_input.mousePosition();
        auto move = m_input.mouseMove();

        if (container.contains(mousePos))
        {
            if (m_input.mouseClick(MouseButton::Left))
            {
                if (m_bubbling)
                {
                    mouseListener.callLeftClick();
                    continue;
                }

                if (!components->any<ZOrderComponent2>())
                {
                    mouseListener.callLeftClick();
                    continue;
                }

                auto& zOrder = components->get<ZOrderComponent2>();
                auto currentZOrderIndex = zOrder.index();
                if (currentZOrderIndex >= maxZOrder)
                {
                    maxZOrder = currentZOrderIndex;
                    clickedMouseListener = &mouseListener;
                }
            }

            if (move)
            {
                if (!hadEnter)
                {
                    mouseListener.callOnEnter();
                    mouseListener.removeEvent(MouseEvent_Exit2);
                }

                mouseListener.callOnHover();
            }
        }
        else if (move && hadEnter)
        {
            mouseListener.callOnExit();
            mouseListener.removeEvent(MouseEvent_Enter2);
            mouseListener.removeEvent(MouseEvent_Hover2);
        }
    }

    if (nullptr != clickedMouseListener)
    {
        clickedMouseListener->callLeftClick();
    }
}

bool MouseEventTriggerSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<ContainerComponent2>()
        && components.any<MouseListenerComponent2>();
}
