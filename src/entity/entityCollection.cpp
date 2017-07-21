//
// entityCollection.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "entityCollection.hpp"

using namespace Jackbengine;

Entity EntityCollection::add()
{
    static size_t entityCounter = 0;

    m_entities[++entityCounter] = std::make_tuple(
        true,
        std::make_unique<ComponentCollection>()
    );

    return entityCounter;
}

void EntityCollection::remove(Entity entity)
{
    m_entities.erase(entity);
}

bool EntityCollection::isEnabled(Entity entity) const
{
    return std::get<0>(find(entity));
}

void EntityCollection::enable(Entity entity)
{
    std::get<0>(find(entity)) = true;
}

void EntityCollection::disable(Entity entity)
{
    std::get<0>(find(entity)) = false;
}

std::tuple<bool, std::unique_ptr<ComponentCollection>>& EntityCollection::find(Entity entity)
{
    return find(*this, entity);
}

const std::tuple<bool, std::unique_ptr<ComponentCollection>>& EntityCollection::find(Entity entity) const
{
    return find(*this, entity);
}
