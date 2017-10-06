//
// systemManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__

#include "system2.hpp"
#include "core/collection/heterogeneousCollection.hpp"

namespace Jackbengine {

class SystemManager
{
    DISALLOW_COPY_AND_MOVE(SystemManager)

public:
    explicit SystemManager(const EntityManager& entityManager);
    ~SystemManager() = default;

    template<typename TSystem, typename ...Args>
    void addSystem(Args&& ...args);

    template<typename TSystem>
    void removeSystem();

    template<typename TSystem>
    TSystem& getSystem();

    template<typename TSystem>
    void enableSystem(bool enable);

    void addEntity(Entity2 entity);
    void removeEntity(Entity2 entity, bool checkComponents);

    void frame(float delta);

private:
    const EntityManager& m_entityManager;

    HeterogeneousCollection<System2> m_systems;
};

template<typename TSystem, typename ...Args>
void SystemManager::addSystem(Args&& ...args)
{
    m_systems.add<TSystem>(std::forward<Args>(args)...);
}

template<typename TSystem>
TSystem& SystemManager::getSystem()
{
    return m_systems.get<TSystem>();
}

template<typename TSystem>
void SystemManager::removeSystem()
{
    m_systems.remove<TSystem>();
}

template<typename TSystem>
void SystemManager::enableSystem(bool enable)
{
    m_systems.enable<TSystem>(enable);
}

} // namespace Jackbengine

#endif // __SYSTEM_MANAGER_H__
