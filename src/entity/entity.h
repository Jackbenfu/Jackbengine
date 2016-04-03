//
//  entity.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 21/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include "common.h"
#include "component/component.h"

NS_BEGIN_JKB
NS_STD

class Entity
{
    friend class EntityManager;

    explicit Entity(const char *name);
    ~Entity();

    void enable();
    void disable();
    bool isEnabled() const;

    template<typename C> C* getComponent();
    template<typename C> C* addComponent();
    template<typename C> bool removeComponent();
    template<typename C> bool enableComponent();
    template<typename C> bool disableComponent();

    map<uint, Component*> m_components;
    bool m_enabled = true;
};

template<typename C>
C* Entity::getComponent()
{
    uint type = C::getType();
    map<uint, Component*>::const_iterator it = m_components.find(type);
    if (m_components.end() != it)
    {
        return static_cast<C*>(it->second);
    }

    return nullptr;
}

template<typename C>
C* Entity::addComponent()
{
    uint type = C::getType();
    map<uint, Component*>::const_iterator it = m_components.find(type);
    if (m_components.end() == it)
    {
        C *component = new C();
        m_components.insert(make_pair(type, component));

        return component;
    }

    return nullptr;
}

template<typename C>
bool Entity::removeComponent()
{
    uint type = C::getType();
    map<uint, Component*>::iterator it = m_components.find(type);
    if (m_components.end() != it)
    {
        DELETE_SAFE(it->second);
        m_components.erase(it);

        return true;
    }

    return false;
}

template<typename C>
bool Entity::enableComponent()
{
    C* component = getComponent<C>();
    if (component)
    {
        static_cast<C*>(component)->enable();

        return true;
    }

    return false;
}

template<typename C>
bool Entity::disableComponent()
{
    C* component = getComponent<C>();
    if (component)
    {
        static_cast<C*>(component)->disable();

        return true;
    }

    return false;
}

NS_END_JKB

#endif // __ENTITY_H__
