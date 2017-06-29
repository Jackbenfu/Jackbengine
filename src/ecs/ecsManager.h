//
// ecsManager.h
// jackbengine
//
// Created by Damien Bendejacq on 17/09/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __ECS_MANAGER_H__
#define __ECS_MANAGER_H__

#include <vector>
#include "entity/entity.h"
#include "system/system.h"

NS_BEGIN_JKB

class EcsManager
{
public:
    EcsManager();
    ~EcsManager();

    // Entity
    bool isEntityEnabled(Entity *entity) const;
    Entity* getEntity(const char *name) const;
    Entity* addEntity(const char *name);
    bool removeEntity(Entity *entity);
    bool removeEntity(const char *name);
    void enableEntity(Entity *entity);
    void enableEntity(const char *name);
    void disableEntity(Entity *entity);
    void disableEntity(const char *name);

    // Component
    template<typename C> C* getComponent(Entity *entity, bool returnIfDisabled = true) const;
    template<typename C> C* getComponentIfEnabled(Entity *entity) const;
    template<typename C> C* addComponent(Entity *entity);
    template<typename C, typename Param> C* addComponent(Entity *entity, Param param);
    template<typename C> bool setComponent(Entity *entity, C *component);
    template<typename C> bool removeComponent(Entity *entity) const;
    template<typename C> bool enableComponent(Entity *entity) const;
    template<typename C> bool disableComponent(Entity *entity) const;

    // System
    template<typename S> S* getSystem();
    template<typename S> S* addSystem();
    template<typename S> void removeSystem();
    template<typename S> void enableSystem();
    template<typename S> void disableSystem();

    void update(float delta);

    void clear();

private:
    vector<Entity*> m_entities;
    vector<System*> m_systems;
    vector<uint> m_systemTypes;

    vector<Entity*>::iterator getEntityIteratorByPtr(Entity *entity);
    vector<Entity*>::const_iterator getEntityIteratorByName(const char *name) const;
    vector<Entity*>::iterator getEntityIteratorByName(const char *name);
};

template<typename C>
C* EcsManager::getComponent(Entity *entity, bool returnIfDisabled) const
{
    if (!entity)
    {
        return nullptr;
    }

    return entity->getComponent<C>(returnIfDisabled);
}

template<typename C>
C* EcsManager::getComponentIfEnabled(Entity *entity) const
{
    return getComponent<C>(entity, false);
}

template<typename C>
C* EcsManager::addComponent(Entity *entity)
{
    if (!entity)
    {
        return nullptr;
    }

    auto component = entity->addComponent<C>();
    if (nullptr == component)
    {
        return nullptr;
    }

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return component;
}

template<typename C, typename Param>
C* EcsManager::addComponent(Entity *entity, Param param)
{
    if (!entity)
    {
        return nullptr;
    }

    auto component = entity->addComponent<C>(param);
    if (nullptr == component)
    {
        return nullptr;
    }

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return component;
}

template<typename C>
bool EcsManager::setComponent(Entity *entity, C *component)
{
    if (!entity)
    {
        return false;
    }

    auto result = entity->setComponent(component);

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return result;
}

template<typename C>
bool EcsManager::removeComponent(Entity *entity) const
{
    if (!entity)
    {
        return false;
    }

    if (!entity->removeComponent<C>())
    {
        return false;
    }

    for (auto system : m_systems)
    {
        system->removeEntity(entity);
    }

    return true;
}

template<typename C>
bool EcsManager::enableComponent(Entity *entity) const
{
    if (!entity)
    {
        return false;
    }

    auto result = entity->enableComponent<C>();

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return result;
}

template<typename C>
bool EcsManager::disableComponent(Entity *entity) const
{
    if (!entity)
    {
        return false;
    }

    auto result = entity->disableComponent<C>();

    for (auto system : m_systems)
    {
        system->removeEntity(entity);
    }

    return result;
}

template<typename S>
S* EcsManager::getSystem()
{
    auto type = S::getType();
    for (auto i = 0; i < m_systemTypes.size(); ++i)
    {
        if (m_systemTypes[i] == type)
        {
            return static_cast<S*>(m_systems[i]);
        }
    }

    return nullptr;
}

template<typename S>
S* EcsManager::addSystem()
{
    auto freshlyAdded = false;

    auto system = getSystem<S>();
    if (!system)
    {
        system = new S();

        m_systemTypes.push_back(S::getType());
        m_systems.push_back(system);

        freshlyAdded = true;
    }

    for (auto entity : m_entities)
    {
        system->addEntity(entity);
    }

    return freshlyAdded ? system : nullptr;
}

template<typename S>
void EcsManager::removeSystem()
{
    disableSystem<S>();
}

template<typename S>
void EcsManager::enableSystem()
{
    auto system = getSystem<S>();
    if (system)
    {
        system->enable();
    }
}

template<typename S>
void EcsManager::disableSystem()
{
    auto type = S::getType();

    auto itType = find(m_systemTypes.begin(), m_systemTypes.end(), type);
    if (m_systemTypes.end() != itType)
    {
        m_systemTypes.erase(itType);
    }

    auto system = getSystem<S>();
    auto itSystem = find(m_systems.begin(), m_systems.end(), system);
    if (m_systems.end() != itSystem)
    {
        DELETE_SAFE(*itSystem);
        m_systems.erase(itSystem);
    }
}

NS_END_JKB

#endif // __ECS_MANAGER_H__
