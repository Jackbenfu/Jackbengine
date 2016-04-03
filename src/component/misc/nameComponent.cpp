//
//  nameComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 20/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "nameComponent.h"

NameComponent::NameComponent()
{
}

NameComponent::~NameComponent()
{
    free(m_name);
}

const char* NameComponent::getName() const
{
    return m_name;
}

void NameComponent::setName(const char *name)
{
    m_name = strdup(name);
}
