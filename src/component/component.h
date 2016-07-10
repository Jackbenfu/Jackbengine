//
//  component.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 25/08/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "common.h"
#include "core/type/typedObject.h"

NS_BEGIN_JKB

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

NS_END_JKB

#endif // __COMPONENT_H__
