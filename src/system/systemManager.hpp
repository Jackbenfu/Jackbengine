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

    template<typename TSystem, typename... Args>
    void addSystem(Args&&... args);

    template<typename TSystem>
    void removeSystem();

    template<typename TSystem>
    void enableSystem();

    template<typename TSystem>
    void disableSystem();

    void addEntity(Entity2 entity);
    void removeEntity(Entity2 entity);

    void frame(float delta);

private:
    const EntityManager& m_entityManager;

    HeterogeneousCollection<System2> m_systems;
};

#include "systemManager.tpp"

} // namespace Jackbengine

#endif // __SYSTEM_MANAGER_H__
