//
//  systemManager.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 21/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "systemManager.h"

SystemManager::SystemManager(EntityManager *entityManager)
: m_entityManager(entityManager)
{
}

SystemManager::~SystemManager()
{
    clear();
}

void SystemManager::update(float delta)
{
    for (auto system : m_systems)
    {
        if (system && system->isEnabled())
        {
            system->update(delta);
        }
    }
}

bool SystemManager::addEntity(Entity *entity)
{
    for (auto system : m_systems)
    {
        if (system && system->isEnabled())
        {
            return system->addEntity(entity);
        }
    }

    return false;
}

bool SystemManager::removeEntity(Entity *entity)
{
    for (auto system : m_systems)
    {
        if (system && system->isEnabled())
        {
            return system->removeEntity(entity);
        }
    }

    return false;
}

bool SystemManager::enableEntity(Entity *entity)
{
    return addEntity(entity);
}

bool SystemManager::disableEntity(Entity *entity)
{
    return removeEntity(entity);
}

void SystemManager::clear()
{
    vector<System*>::iterator it = m_systems.begin();
    while (m_systems.end() != it)
    {
        DELETE_SAFE(*it);
        ++it;
    }
    m_systems.clear();
    m_systemTypes.clear();
}
