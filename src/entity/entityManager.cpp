//
// entityManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "entityManager.hpp"

using namespace Jackbengine;

Entity2 EntityManager::add()
{
    static size_t entityCounter = 0;

    m_entities[++entityCounter] = std::make_tuple(
        true,
        std::make_unique<ComponentCollection>()
    );

    return entityCounter;
}

void EntityManager::remove(Entity2 entity)
{
    m_entities.erase(entity);
}

bool EntityManager::isEnabled(Entity2 entity) const
{
    return std::get<0>(find(entity));
}

void EntityManager::enable(Entity2 entity)
{
    std::get<0>(find(entity)) = true;
}

void EntityManager::disable(Entity2 entity)
{
    std::get<0>(find(entity)) = false;
}

std::tuple<bool, std::unique_ptr<ComponentCollection>>& EntityManager::find(Entity2 entity)
{
    return find(*this, entity);
}

const std::tuple<bool, std::unique_ptr<ComponentCollection>>& EntityManager::find(Entity2 entity) const
{
    return find(*this, entity);
}
