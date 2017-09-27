//
// entity.tpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_TPP__
#define __ENTITY_TPP__

template<typename TComponent>
TComponent* Entity::getComponent(bool returnIfDisabled)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto typeId = GET_TYPE_ID(TComponent);
    auto it = m_components.find(typeId);
    if (m_components.end() == it)
    {
        return nullptr;
    }

    if (it->second->isEnabled() ||
        (returnIfDisabled && !it->second->isEnabled()))
    {
        return static_cast<TComponent*>(it->second);
    }

    return nullptr;
}

template<typename TComponent>
TComponent* Entity::getComponentIfEnabled()
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    return getComponent<TComponent>(false);
}

template<typename TComponent>
TComponent* Entity::addComponent()
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto typeId = GET_TYPE_ID(TComponent);
    auto it = m_components.find(typeId);
    if (m_components.end() != it)
    {
        return nullptr;
    }

    auto component = new TComponent();
    m_components.insert(std::make_pair(typeId, component));

    return component;
}

template<typename TComponent, typename TParam>
TComponent* Entity::addComponent(TParam param)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto typeId = GET_TYPE_ID(TComponent);
    auto it = m_components.find(typeId);
    if (m_components.end() != it)
    {
        return nullptr;
    }

    auto component = new TComponent(param);
    m_components.insert(std::make_pair(typeId, component));

    return component;
}

template<typename TComponent>
bool Entity::setComponent(TComponent *component)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto typeId = GET_TYPE_ID(TComponent);
    auto it = m_components.find(typeId);

    if (m_components.end() != it)
    {
        m_components[typeId] = component;
    }
    else
    {
        m_components.insert(make_pair(typeId, component));
    }

    return true;
}

template<typename TComponent>
bool Entity::removeComponent()
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto typeId = GET_TYPE_ID(TComponent);
    auto it = m_components.find(typeId);
    if (m_components.end() == it)
    {
        return false;
    }

    DELETE_SAFE(it->second);
    m_components.erase(it);

    return true;
}

template<typename TComponent>
bool Entity::enableComponent()
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto component = getComponent<TComponent>();
    if (!component)
    {
        return false;
    }

    component->enable();

    return true;
}

template<typename TComponent>
bool Entity::disableComponent()
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    auto component = getComponent<TComponent>();
    if (!component)
    {
        return false;
    }

    component->disable();

    return true;
}

#endif // __ENTITY_TPP__
