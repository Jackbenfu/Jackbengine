//
// entity.cpp
// jackbengine
//
// Created by Damien Bendejacq on 27/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "entity.h"
#include "component/misc/nameComponent.h"

Entity::Entity(const char *name)
{
    addComponent<NameComponent>()->setName(name);
}

Entity::~Entity()
{
    /*for (auto pair : m_components)
    {
        DELETE_SAFE(pair.second);
    }*/
    m_components.clear();
}

void Entity::enable()
{
    m_enabled = true;
}

void Entity::disable()
{
    m_enabled = false;
}

bool Entity::isEnabled() const
{
    return m_enabled;
}
