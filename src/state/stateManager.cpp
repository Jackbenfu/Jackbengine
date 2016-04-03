//
//  stateManager.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 28/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "stateManager.h"

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

void StateManager::push(State *state)
{
    m_states.push_back(state);
    m_states.back()->onEnter();
}

void StateManager::pop()
{
    if (!m_states.empty())
    {
        State *state = m_states.back();

        state->onExit();
        DELETE_SAFE(state);
        m_states.pop_back();
    }
}
