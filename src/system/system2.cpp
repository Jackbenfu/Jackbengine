//
// system2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "system2.hpp"

using namespace Jackbengine;

void System2::addEntity(Entity2 entity, ComponentCollection& components)
{
    if (!hasRequiredComponents(components))
    {
        return;
    }

    m_entities[entity] = &components;
}

void System2::removeEntity(Entity2 entity, bool checkComponents)
{
    if (!checkComponents)
    {
        m_entities.erase(entity);
    }

    const auto it = m_entities.find(entity);
    if (it == m_entities.end())
    {
        return;
    }

    if (hasRequiredComponents(*it->second))
    {
        return;
    }

    m_entities.erase(entity);
}
