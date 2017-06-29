//
// mouseEventTriggerSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 28/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "mouseEventTriggerSystem.h"
#include "component/layout/containerComponent.h"
#include "component/input/mouseListenerComponent.h"
#include "component/layout/zOrderComponent.h"

MouseEventTriggerSystem::MouseEventTriggerSystem()
{
}

MouseEventTriggerSystem::~MouseEventTriggerSystem()
{
}

void MouseEventTriggerSystem::update(float delta)
{
    UNUSED(delta);

    MouseListenerComponent *clickedMouseListener {nullptr};
    auto maxZOrder = 0;

    for (auto entity : m_entities)
    {
        if (!entity->isEnabled())
        {
            continue;
        }

        auto container = entity->getComponentIfEnabled<ContainerComponent>();
        auto mouseListener = entity->getComponentIfEnabled<MouseListenerComponent>();
        if (!container || !mouseListener)
        {
            continue;
        }

        auto hadEnter = mouseListener->hasEvent(MouseEvent_Enter);
        auto mousePos = m_input->getMousePosition();
        auto move = m_input->mouseMove();

        if (container->contains(mousePos))
        {
            if (m_input->mouseClick(MouseButton::Left))
            {
                if (m_bubblingActive)
                {
                    mouseListener->callLeftClick();
                    continue;
                }

                auto zOrder = entity->getComponentIfEnabled<ZOrderComponent>();
                if (!zOrder)
                {
                    mouseListener->callLeftClick();
                    continue;
                }

                auto currentZOrder = zOrder->getIndex();
                if (currentZOrder >= maxZOrder)
                {
                    maxZOrder = currentZOrder;
                    clickedMouseListener = mouseListener;
                }
            }

            if (move)
            {
                if (!hadEnter)
                {
                    mouseListener->callOnEnter();
                    mouseListener->removeEvent(MouseEvent_Exit);
                }

                mouseListener->callOnHover();
            }
        }
        else if (move && hadEnter)
        {
            mouseListener->callOnExit();
            mouseListener->removeEvent(MouseEvent_Enter);
            mouseListener->removeEvent(MouseEvent_Hover);
        }
    }

    if (clickedMouseListener)
    {
        clickedMouseListener->callLeftClick();
    }
}

bool MouseEventTriggerSystem::hasRequiredComponents(Entity *entity)
{
    return entity->getComponentIfEnabled<ContainerComponent>() &&
        entity->getComponentIfEnabled<MouseListenerComponent>();
}

void MouseEventTriggerSystem::setBubblingActive(bool active)
{
    m_bubblingActive = active;
}

void MouseEventTriggerSystem::setInput(Input *input)
{
    m_input = input;
}
