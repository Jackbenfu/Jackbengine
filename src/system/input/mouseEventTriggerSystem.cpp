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
            ContainerComponent *container = em()->getComponent<ContainerComponent>(entity);
            MouseListenerComponent *mouseListener = em()->getComponent<MouseListenerComponent>(entity);

            bool hadEnter = mouseListener->hasEvent(MouseEvent_Enter);

            Vec2i mousePos = m_input->getMousePosition();
            bool move = m_input->mouseMove();

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
    return em()->getComponent<ContainerComponent>(entity) &&
        em()->getComponent<MouseListenerComponent>(entity);
}

void MouseEventTriggerSystem::setBubblingActive(bool active)
{
    m_bubblingActive = active;
}

void MouseEventTriggerSystem::setInput(Input *input)
{
    m_input = input;
}
