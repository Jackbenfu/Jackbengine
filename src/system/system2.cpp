//
// system2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "system2.hpp"

using namespace Jackbengine;

System2::System2(const EntityManager& entityManager)
    : m_entityManager {entityManager}
{
    // Nothing
}

System2::~System2() = default;

const EntityManager& System2::em() const
{
    return m_entityManager;
}
