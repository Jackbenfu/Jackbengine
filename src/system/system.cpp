//
// system.cpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "system.hpp"

using namespace Jackbengine;

void System::sort(
    std::function<bool(
        std::pair<Entity, ComponentCollection*>,
        std::pair<Entity, ComponentCollection*>
    )> comparison
)
{
    m_entities.sort(std::move(comparison));
}

void System::addEntity(Entity entity, ComponentCollection& components)
{
    if (!hasRequiredComponents(components))
    {
        return;
    }

    m_entities.emplace_front(
        std::make_pair(entity, &components)
    );
}

void System::removeEntity(Entity entity, bool checkComponents)
{
    auto it = m_entities.begin();
    while (it != m_entities.end())
    {
        if (it->first == entity)
        {
            break;
        }

        ++it;
    }

    if (it == m_entities.end())
    {
        return;
    }

    if (checkComponents && hasRequiredComponents(*it->second))
    {
        return;
    }

    m_entities.erase(it);
}
