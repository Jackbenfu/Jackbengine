//
// ecsManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 30/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __ECS_MANAGER_H__
#define __ECS_MANAGER_H__

#include "entity/entityManager.hpp"
#include "system/systemManager.hpp"

namespace Jackbengine {

class EcsManager
{
DISALLOW_COPY_AND_MOVE(EcsManager)

public:
    EcsManager();
    ~EcsManager() = default;

    /*
     * Entity
     */
    Entity addEntity();
    void removeEntity(Entity entity);
    void enableEntity(Entity entity, bool enable);

    /*
     * Component
     */
    template<typename TComponent, typename ...Args>
    TComponent *addComponent(Entity entity, Args&& ...args);

    template<typename TComponent>
    TComponent *getComponent(Entity entity) const;

    template<typename TComponent>
    bool hasComponent(Entity entity) const;

    template<typename TComponent>
    void enableComponent(Entity entity, bool enable);

    /*
     * System
     */
    template<typename TSystem, typename ...Args>
    void addSystem(Args&& ...args);

    template<typename TSystem>
    TSystem *getSystem();

    template<typename TSystem>
    void enableSystem(bool enable);

    void frame(float delta);

    inline static EcsManager& getManager()
    {
        return s_ecsManager;
    }

private:
    std::unique_ptr<EntityManager> m_entityManager;
    std::unique_ptr<SystemManager> m_systemManager;

    static EcsManager s_ecsManager;
};

template<typename TComponent, typename... Args>
TComponent *EcsManager::addComponent(Entity entity, Args&& ... args)
{
    const auto component = m_entityManager->addComponent<TComponent>(entity, std::forward<Args>(args)...);

    if (m_entityManager->isEntityEnabled(entity))
    {
        m_systemManager->addEntity(entity);
    }

    return component;
}

template<typename TComponent>
TComponent *EcsManager::getComponent(Entity entity) const
{
    return m_entityManager->getComponent<TComponent>(entity);
}

template<typename TComponent>
bool EcsManager::hasComponent(Entity entity) const
{
    return m_entityManager->hasComponent<TComponent>(entity);
}

template<typename TComponent>
void EcsManager::enableComponent(Entity entity, bool enable)
{
    m_entityManager->enableComponent<TComponent>(entity, enable);
    if (enable)
    {
        m_systemManager->addEntity(entity);
    }
    else
    {
        m_systemManager->removeEntity(entity, true);
    }
}

template<typename TSystem, typename ...Args>
void EcsManager::addSystem(Args&& ...args)
{
    m_systemManager->addSystem<TSystem>(std::forward<Args>(args)...);
}

template<typename TSystem>
TSystem *EcsManager::getSystem()
{
    return m_systemManager->getSystem<TSystem>();
}

template<typename TSystem>
void EcsManager::enableSystem(bool enable)
{
    m_systemManager->enableSystem<TSystem>(enable);
}

}

#endif // __ECS_MANAGER_H__
