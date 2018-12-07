//
// mouseEventTriggerSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "mouseEventTriggerSystem.hpp"
#include "component/layout/containerComponent.hpp"
#include "component/input/mouseListenerComponent.hpp"
#include "component/layout/zIndexComponent.hpp"

namespace Jackbengine {

MouseEventTriggerSystem::MouseEventTriggerSystem(const Input& input)
    : m_input {input}
{
}

int MouseEventTriggerSystem::order() const
{
    return (int) SystemOrder::MouseEventTrigger;
}

void MouseEventTriggerSystem::frame(float)
{
    MouseListenerComponent *clickedMouseListener {nullptr};
    uint clickedMaxZIndex = {0};

    MouseListenerComponent *hoveredMouseListener {nullptr};
    uint hoveredMaxZIndex {0};
    bool hoveredHasEnter {false};

    for (const auto&[entity, components] : entities())
    {
        const auto container = components->get<ContainerComponent>();
        const auto zIndex = components->get<ZIndexComponent>();
        auto mouseListener = components->get<MouseListenerComponent>();

        auto hadEnter = mouseListener->hasEvent(MouseEvent_Enter);
        auto currentZIndex = zIndex->index();

        auto mousePos = m_input.mousePosition();
        auto move = m_input.mouseMove();

        if (container->contains(mousePos))
        {
            if (m_input.mouseClick(MouseButton::Left))
            {
                if (currentZIndex >= clickedMaxZIndex)
                {
                    clickedMaxZIndex = currentZIndex;
                    clickedMouseListener = mouseListener;
                }
            }

            if (move)
            {
                if (currentZIndex >= hoveredMaxZIndex)
                {
                    hoveredMaxZIndex = currentZIndex;
                    hoveredMouseListener = mouseListener;
                    hoveredHasEnter = hadEnter;
                }
            }
        }
        else if (move && hadEnter)
        {
            mouseListener->callOnExit();
            mouseListener->removeEvent(MouseEvent_Enter);
            mouseListener->removeEvent(MouseEvent_Hover);
        }
    }

    if (nullptr != clickedMouseListener)
    {
        clickedMouseListener->callLeftClick();
    }

    if (nullptr != hoveredMouseListener)
    {
        if (!hoveredHasEnter)
        {
            hoveredMouseListener->callOnEnter();
            hoveredMouseListener->removeEvent(MouseEvent_Exit);
        }

        hoveredMouseListener->callOnHover();
    }
}

bool MouseEventTriggerSystem::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<ContainerComponent>()
           && components.any<MouseListenerComponent>()
           && components.any<ZIndexComponent>();
}

}
