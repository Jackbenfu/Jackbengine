//
// state.h
// jackbengine
//
// Created by Damien Bendejacq on 27/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __STATE_H__
#define __STATE_H__

#include "common.h"

NS_BEGIN_JKB

class State
{
public:
    State();
    virtual ~State();

    virtual void onEnter() = 0;
    virtual void update(float delta) = 0;
    virtual void onExit() = 0;
};

NS_END_JKB

#endif // __STATE_H__
