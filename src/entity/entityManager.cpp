//
//  entityManager.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 02/07/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "entityManager.h"
#include "component/misc/nameComponent.h"

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
    clear();
}

Entity* EntityManager::addEntity(const char *name)
{
    vector<Entity*>::const_iterator it = m_entities.begin();
    while (m_entities.end() != it)
    {
        Entity *entity = *it;

        NameComponent *nameComponent = entity->getComponent<NameComponent>();
        if (nameComponent && 0 == strcmp(name, nameComponent->getName()))
        {
            return nullptr;
        }

        ++it;
    }

    Entity *entity = new Entity(name);
    m_entities.push_back(entity);

    return entity;
}

bool EntityManager::removeEntity(Entity *entity)
{
    vector<Entity*>::iterator it = m_entities.begin();
    while (m_entities.end() != it)
    {
        if (*it == entity)
        {
            DELETE_SAFE(*it);
            entity = nullptr;
            m_entities.erase(it);

            return true;
        }
    }

    return false;
}

bool EntityManager::enableEntity(Entity *entity) const
{
    if (entity)
    {
        entity->enable();

        return true;
    }

    return false;
}

bool EntityManager::disableEntity(Entity *entity) const
{
    if (entity)
    {
        entity->disable();

        return true;
    }

    return false;
}

bool EntityManager::isEntityEnabled(Entity *entity) const
{
    return entity && entity->isEnabled();
}

void EntityManager::clear()
{
    for (auto entity : m_entities)
    {
        DELETE_SAFE(entity);
    }
    m_entities.clear();
}
