//
// ecsManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 30/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#include "core/log/log.hpp"
#include "ecsManager.hpp"

namespace Jackbengine {

EcsManager EcsManager::s_ecsManager;

EcsManager::EcsManager()
    : m_entityManager {std::make_unique<EntityManager>()},
      m_systemManager {std::make_unique<SystemManager>(*m_entityManager)}
{
}

Entity EcsManager::addEntity()
{
    return m_entityManager->addEntity();
}

void EcsManager::removeEntity(Entity entity)
{
    m_entityManager->removeEntity(entity);
    m_systemManager->removeEntity(entity, false);
}

void EcsManager::enableEntity(Entity entity, bool enable)
{
    m_entityManager->enableEntity(entity, enable);

    if (enable)
    {
        m_systemManager->addEntity(entity);
    }
    else
    {
        m_systemManager->removeEntity(entity, false);
    }
}

void EcsManager::frame(float delta)
{
    m_systemManager->frame(delta);
}

}
