//
// eventManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "eventManager.h"

namespace Jackbengine::details {

EventManager::EventManager(EventManager::EventCallbackFunc callbackFunc)
    : m_callbackFunc {std::move(callbackFunc)}
{
}

void EventManager::update()
{
    SDL_Event event {};
    while (SDL_PollEvent(&event) > 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                ApplicationClosedEvent e;
                m_callbackFunc(e);
                break;
            }

            default:
                break;
        }
    }
}

}
