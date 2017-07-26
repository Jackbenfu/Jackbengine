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
{
    // Nothing
}

SystemManager::~SystemManager() = default;
