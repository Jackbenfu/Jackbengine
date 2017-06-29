//
// entity.h
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
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
    friend class EcsManager;

public:
    bool isEnabled() const;

    template<typename C> C* getComponent(bool returnIfDisabled = true);
    template<typename C> C* getComponentIfEnabled();

private:
    explicit Entity(const char *name);
    ~Entity();

    void enable();
    void disable();

    template<typename C> C* addComponent();
    template<typename C, typename Param> C* addComponent(Param *param);
    template<typename C> bool setComponent(C *component);
    template<typename C> bool removeComponent();
    template<typename C> bool enableComponent();
    template<typename C> bool disableComponent();

    map<uint, Component*> m_components;
    bool m_enabled = true;
};

template<typename C>
C* Entity::getComponent(bool returnIfDisabled)
{
    auto type = C::getType();
    auto it = m_components.find(type);
    if (m_components.end() == it)
    {
        return nullptr;
    }

    if (it->second->isEnabled() ||
        (returnIfDisabled && !it->second->isEnabled()))
    {
        return static_cast<C*>(it->second);
    }

    return nullptr;
}

template<typename C>
C* Entity::getComponentIfEnabled()
{
    return getComponent<C>(false);
}

template<typename C>
C* Entity::addComponent()
{
    auto type = C::getType();
    auto it = m_components.find(type);
    if (m_components.end() != it)
    {
        return nullptr;
    }

    auto component = new C();
    m_components.insert(make_pair(type, component));

    return component;
}

template<typename C, typename Param>
C* Entity::addComponent(Param *param)
{
    auto type = C::getType();
    auto it = m_components.find(type);
    if (m_components.end() != it)
    {
        return nullptr;
    }

    auto component = new C(param);
    m_components.insert(make_pair(type, component));

    return component;
}

template<typename C>
bool Entity::setComponent(C *component)
{
    auto type = C::getType();
    auto it = m_components.find(type);

    if (m_components.end() != it)
    {
        m_components[type] = component;
    }
    else
    {
        m_components.insert(make_pair(type, component));
    }

    return true;
}

template<typename C>
bool Entity::removeComponent()
{
    auto type = C::getType();
    auto it = m_components.find(type);
    if (m_components.end() == it)
    {
        return false;
    }

    DELETE_SAFE(it->second);
    m_components.erase(it);

    return true;
}

template<typename C>
bool Entity::enableComponent()
{
    auto component = getComponent<C>();
    if (!component)
    {
        return false;
    }

    component->enable();

    return true;
}

template<typename C>
bool Entity::disableComponent()
{
    auto component = getComponent<C>();
    if (!component)
    {
        return false;
    }

    component->disable();

    return true;
}

NS_END_JKB

#endif // __ENTITY_H__
