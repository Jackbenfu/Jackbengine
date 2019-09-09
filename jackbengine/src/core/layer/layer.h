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

namespace Jackbengine::details {

class Layer
{
public:
    explicit Layer(const std::string &name);
    virtual ~Layer() = default;

    virtual void frame(float delta) = 0;

private:
    const std::string &m_name;
};

}

#endif // __LAYER_H__
