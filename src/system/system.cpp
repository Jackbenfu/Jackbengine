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
    if (!hasRequiredComponents(components) || doesEntityExists(entity))
    {
        return;
    }

    m_entityStatuses.insert_or_assign(entity, EntityStatus::Enabled);
    m_entities.emplace_front(std::make_pair(entity, &components));
}

void System::removeEntity(Entity entity, bool checkComponents)
{
    auto it = m_entities.begin();
    while (it != m_entities.end())
    {
        if (it->first == entity)
        {
            if (checkComponents && hasRequiredComponents(*it->second))
            {
                return;
            }

            m_entityStatuses.insert_or_assign(entity, EntityStatus::ToRemove);
            return;
        }

        ++it;
    }
}

bool System::doesEntityExists(Jackbengine::Entity entity) const
{
    return m_entityStatuses.find(entity) != m_entityStatuses.end();
}

void System::clean()
{
    auto it = m_entities.begin();
    while (it != m_entities.end())
    {
        auto entity = it->first;
        auto status = m_entityStatuses[entity];

        if (status == EntityStatus::ToRemove)
        {
            m_entityStatuses.erase(entity);
            m_entities.erase(it);
        }

        ++it;
    }
}
