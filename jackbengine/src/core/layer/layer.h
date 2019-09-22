//
// layer.h
// jackbengine
//
// Created by Damien Bendejacq on 05/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __LAYER_H__
#define __LAYER_H__

#include <string>

#include "core/event/event.h"

namespace Jackbengine {

class Layer
{
public:
    Layer() = default;
    virtual ~Layer() = default;

    virtual void update(float delta) = 0;
    virtual void onEvent(Event &e) = 0;
};

}

#endif // __LAYER_H__
