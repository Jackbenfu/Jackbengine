//
// systemManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "systemManager.hpp"

using namespace Jackbengine;

SystemManager::SystemManager(const EntityManager& entityManager)
    : m_entityManager {entityManager}
{ }

void SystemManager::addEntity(Entity2 entity)
{
    auto& components = m_entityManager.getEntity(entity);

    const auto lambda = [&](System2& system)
    {
        system.addEntity(entity, components);
    };

    m_systems.apply(lambda);
}

void SystemManager::removeEntity(Entity2 entity, bool checkComponents)
{
    const auto lambda = [&](System2& system)
    {
        system.removeEntity(entity, checkComponents);
    };

    m_systems.apply(lambda);
}

void SystemManager::frame(float delta)
{
    const auto lambda = [&delta](System2& system)
    {
        system.frame(delta);
    };

    // TODO handle system execution order

    m_systems.apply(lambda);
}
