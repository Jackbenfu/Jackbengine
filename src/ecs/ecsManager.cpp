//
// ecsManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/09/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#include "ecsManager.hpp"
#include "component/misc/nameComponent.hpp"

using namespace std;
using namespace Jackbengine;

EcsManager::EcsManager() = default;

EcsManager::~EcsManager()
{
    clear();
}

bool EcsManager::isEntityEnabled(Entity *entity) const
{
    return entity->isEnabled();
}

Entity* EcsManager::getEntity(const char *name) const
{
    auto it = getEntityIteratorByName(name);
    if (m_entities.end() != it)
    {
        return *it;
    }

    return nullptr;
}

Entity* EcsManager::addEntity(const char *name)
{
    auto it = getEntityIteratorByName(name);
    if (m_entities.end() != it)
    {
        LOG_ERROR("Entity %s already exists", name);
        return nullptr;
    }

    auto entity = new Entity(name);
    m_entities.push_back(entity);

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return entity;
}

bool EcsManager::removeEntity(Entity *entity)
{
    auto it = getEntityIteratorByPtr(entity);
    if (m_entities.end() != it)
    {
        for (auto system : m_systems)
        {
            system->removeEntity(entity);
        }

        DELETE_SAFE(*it);
        m_entities.erase(it);

        return true;
    }

    return false;
}

bool EcsManager::removeEntity(const char *name)
{
    auto it = getEntityIteratorByName(name);
    if (m_entities.end() != it)
    {
        for (auto system : m_systems)
        {
            system->removeEntity(*it);
        }

        DELETE_SAFE(*it);
        m_entities.erase(it);

        return true;
    }

    return false;
}

void EcsManager::enableEntity(Entity *entity)
{
    auto it = getEntityIteratorByPtr(entity);
    if (m_entities.end() != it)
    {
        entity->enable();

        for (auto system : m_systems)
        {
            system->addEntity(entity);
        }
    }
}

void EcsManager::enableEntity(const char *name)
{
    auto it = getEntityIteratorByName(name);
    if (m_entities.end() != it)
    {
        (*it)->enable();

        for (auto system : m_systems)
        {
            system->addEntity(*it);
        }
    }
}

void EcsManager::disableEntity(Entity *entity)
{
    auto it = getEntityIteratorByPtr(entity);
    if (m_entities.end() != it)
    {
        entity->disable();

        for (auto system : m_systems)
        {
            system->removeEntity(entity);
        }
    }
}

void EcsManager::disableEntity(const char *name)
{
    auto it = getEntityIteratorByName(name);
    if (m_entities.end() != it)
    {
        (*it)->disable();

        for (auto system : m_systems)
        {
            system->removeEntity(*it);
        }
    }
}

void EcsManager::update(float delta)
{
    for (auto system : m_systems)
    {
        if (system && system->isEnabled())
        {
            system->update(delta);
        }
    }
}

void EcsManager::clear()
{
    for (auto entity : m_entities)
    {
        DELETE_SAFE(entity);
    }
    m_entities.clear();

    auto it = m_systems.begin();
    while (m_systems.end() != it)
    {
        DELETE_SAFE(*it);
        ++it;
    }
    m_systems.clear();
    m_systemTypes.clear();
}

vector<Entity*>::iterator EcsManager::getEntityIteratorByPtr(Entity *entity)
{
    auto it = m_entities.begin();
    while (m_entities.end() != it)
    {
        if (*it == entity)
        {
            return it;
        }

        ++it;
    }

    return m_entities.end();
}

vector<Entity*>::const_iterator EcsManager::getEntityIteratorByName(const char *name) const
{
    auto it = m_entities.begin();
    while (m_entities.end() != it)
    {
        auto entity = *it;
        auto nameComponent = entity->getComponent<NameComponent>();
        if (nameComponent && 0 == strcmp(name, nameComponent->getName()))
        {
            return it;
        }

        ++it;
    }

    return m_entities.end();
}

vector<Entity*>::iterator EcsManager::getEntityIteratorByName(const char *name)
{
    auto it = m_entities.begin();
    while (m_entities.end() != it)
    {
        auto entity = *it;
        auto nameComponent = entity->getComponent<NameComponent>();
        if (nameComponent && 0 == strcmp(name, nameComponent->getName()))
        {
            return it;
        }

        ++it;
    }

    return m_entities.end();
}
