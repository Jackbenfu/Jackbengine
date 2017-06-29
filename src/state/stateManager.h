//
// stateManager.h
// jackbengine
//
// Created by Damien Bendejacq on 28/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __STATE_MANAGER_H__
#define __STATE_MANAGER_H__

#include <vector>
#include "state.h"

NS_BEGIN_JKB
NS_STD

class StateManager
{
public:
    StateManager();
    ~StateManager();

    void push(State *state);
    void pop();

private:
    vector<State*> m_states;
};

NS_END_JKB

#endif // __STATE_MANAGER_H__
