//
//  component.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 25/08/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "component.h"

Component::Component()
{
}

void Component::enable()
{
    m_enabled = true;
}

void Component::disable()
{
    m_enabled = false;
}

bool Component::isEnabled() const
{
    return m_enabled;
}
