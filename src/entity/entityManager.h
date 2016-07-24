//
//  entityManager.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 02/07/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include <vector>
#include "entity.h"

NS_BEGIN_JKB
NS_STD

class EntityManager
{
    friend class Scene;
    friend class SystemManager;

public:
    Entity* addEntity(const char *name);
    bool removeEntity(Entity *entity);
    bool enableEntity(Entity *entity) const;
    bool disableEntity(Entity *entity) const;
    bool isEntityEnabled(Entity *entity) const;

    template<typename C> C* getComponent(Entity *entity, bool returnIfDisabled = true) const;
    template<typename C> C* getComponentIfEnabled(Entity *entity) const;
    template<typename C> C* addComponent(Entity *entity);
    template<typename C> bool removeComponent(Entity *entity) const;
    template<typename C> bool enableComponent(Entity *entity) const;
    template<typename C> bool disableComponent(Entity *entity) const;

private:
    EntityManager();
    ~EntityManager();

    void clear();

    vector<Entity*> m_entities;
};

template<typename C>
C* EntityManager::getComponent(Entity *entity, bool returnIfDisabled) const
{
    if (entity)
    {
        return entity->getComponent<C>(returnIfDisabled);
    }

    return nullptr;
}

template<typename C>
C* EntityManager::getComponentIfEnabled(Entity *entity) const
{
    return getComponent<C>(entity, false);
}

template<typename C>
C* EntityManager::addComponent(Entity *entity)
{
    if (entity)
    {
        return entity->addComponent<C>();
    }

    return nullptr;
}

template<typename C>
bool EntityManager::removeComponent(Entity *entity) const
{
    if (entity)
    {
        return entity->removeComponent<C>();
    }

    return false;
}

template<typename C>
bool EntityManager::enableComponent(Entity *entity) const
{
    if (entity)
    {
        return entity->enableComponent<C>();
    }

    return false;
}

template<typename C>
bool EntityManager::disableComponent(Entity *entity) const
{
    if (entity)
    {
        return entity->disableComponent<C>();
    }

    return false;
}

NS_END_JKB

#endif // __ENTITY_MANAGER_H__
