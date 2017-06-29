//
// system.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "system.h"

System::System()
{
}

System::~System()
{
    m_entities.clear();
}

bool System::isEnabled() const
{
    return m_enabled;
}

void System::enable()
{
    m_enabled = true;
}

void System::disable()
{
    m_enabled = false;
}

bool System::addEntity(Entity *entity)
{
    for (auto theEntity : m_entities)
    {
        if (theEntity == entity)
        {
            return false;
        }
    }

    if (hasRequiredComponents(entity))
    {
        m_entities.push_back(entity);

        return true;
    }

    return false;
}

bool System::removeEntity(Entity *entity)
{
    for (vector<Entity*>::const_iterator it = m_entities.begin(); m_entities.end() != it; ++it)
    {
        if (*it == entity &&
            !hasRequiredComponents(entity))
        {
            m_entities.erase(it);

            return true;
        }
    }

    return false;
}
