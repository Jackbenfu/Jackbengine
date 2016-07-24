//
//  mouseEventTriggerSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 28/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "mouseEventTriggerSystem.h"
#include "component/layout/containerComponent.h"
#include "component/input/mouseListenerComponent.h"

MouseEventTriggerSystem::MouseEventTriggerSystem()
{
}

MouseEventTriggerSystem::~MouseEventTriggerSystem()
{
}

void MouseEventTriggerSystem::update(float delta)
{
    UNUSED(delta)

    for (auto entity : m_entities)
    {
        if (em()->isEntityEnabled(entity))
        {
            auto container = em()->getComponentIfEnabled<ContainerComponent>(entity);
            auto mouseListener = em()->getComponentIfEnabled<MouseListenerComponent>(entity);

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
                    mouseListener->callLeftClick();
                    if (!m_bubblingActive)
                    {
                        return;
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
    }
}

bool MouseEventTriggerSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponentIfEnabled<ContainerComponent>(entity) &&
        em()->getComponentIfEnabled<MouseListenerComponent>(entity);
}

void MouseEventTriggerSystem::setBubblingActive(bool active)
{
    m_bubblingActive = active;
}

void MouseEventTriggerSystem::setInput(Input *input)
{
    m_input = input;
}
