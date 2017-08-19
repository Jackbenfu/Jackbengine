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

void System2::removeEntity(Entity2 entity)
{
    m_entities.erase(entity);
}
