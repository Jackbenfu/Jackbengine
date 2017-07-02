//
// component.hpp
// jackbengine
//
// Created by Damien Bendejacq on 25/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "common.hpp"

namespace Jackbengine {

class Component
{
    friend class Entity;

public:
    bool isEnabled() const;

protected:
    Component();

private:
    void enable();
    void disable();

    bool m_enabled = true;
};

} // namespace Jackbengine

#endif // __COMPONENT_H__
