//
// nameComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "nameComponent.hpp"
#include "platform.hpp"

using namespace Jackbengine;

NameComponent::NameComponent() = default;

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
