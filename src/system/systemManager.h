//
//  systemManager.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 21/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__

#include <vector>
#include "common.h"
#include "system.h"

NS_BEGIN_JKB
NS_STD

class SystemManager
{
    friend class Scene;

    explicit SystemManager(EntityManager *entityManager);
    ~SystemManager();

    void update(float delta);

    template<typename S> S* addSystem();
    template<typename S> bool enableSystem();
    template<typename S> bool disableSystem();

    template<typename S> System* getSystem();

    bool addEntity(Entity *entity);
    bool removeEntity(Entity *entity);
    bool enableEntity(Entity *entity);
    bool disableEntity(Entity *entity);

    void clear();

    vector<System*> m_systems;
    vector<uint> m_systemTypes;

    EntityManager *m_entityManager;
};

template<typename S>
S* SystemManager::addSystem()
{
    System *system = getSystem<S>();
    if (!system)
    {
        system = new S();
        system->setEntityManager(m_entityManager);

        m_systemTypes.push_back(S::getType());
        m_systems.push_back(system);

        for (auto entity : m_entityManager->m_entities)
        {
            system->addEntity(entity);
        }

        return static_cast<S*>(system);
    }

    return nullptr;
}

template<typename S>
bool SystemManager::enableSystem()
{
    System *system = getSystem<S>();
    if (system)
    {
        system->enable();

        return true;
    }


    return false;
}

template<typename S>
bool SystemManager::disableSystem()
{
    System *system = getSystem<S>();
    if (system)
    {
        system->disable();

        return true;
    }
    
    return false;
}

template<typename S>
System* SystemManager::getSystem()
{
    uint type = S::getType();
    for (size_t i = 0; i < m_systemTypes.size(); ++i)
    {
        if (m_systemTypes[i] == type)
        {
            return m_systems[i];
        }
    }

    return nullptr;
}

NS_END_JKB

#endif // __SYSTEM_MANAGER_H__
