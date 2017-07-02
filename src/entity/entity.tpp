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
    ASSERT_IS_BASE_OF(Component, TComponent);

    auto hashCode = GET_HASH_CODE(TComponent);
    auto it = m_components.find(hashCode);
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
    ASSERT_IS_BASE_OF(Component, TComponent);

    return getComponent<TComponent>(false);
}

template<typename TComponent>
TComponent* Entity::addComponent()
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    auto hashCode = GET_HASH_CODE(TComponent);
    auto it = m_components.find(hashCode);
    if (m_components.end() != it)
    {
        return nullptr;
    }

    auto component = new TComponent();
    m_components.insert(std::make_pair(hashCode, component));

    return component;
}

template<typename TComponent, typename TParam>
TComponent* Entity::addComponent(TParam param)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    auto hashCode = GET_HASH_CODE(TComponent);
    auto it = m_components.find(hashCode);
    if (m_components.end() != it)
    {
        return nullptr;
    }

    auto component = new TComponent(param);
    m_components.insert(std::make_pair(hashCode, component));

    return component;
}

template<typename TComponent>
bool Entity::setComponent(TComponent *component)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    auto hashCode = GET_HASH_CODE(TComponent);
    auto it = m_components.find(hashCode);

    if (m_components.end() != it)
    {
        m_components[hashCode] = component;
    }
    else
    {
        m_components.insert(make_pair(hashCode, component));
    }

    return true;
}

template<typename TComponent>
bool Entity::removeComponent()
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    auto hashCode = GET_HASH_CODE(TComponent);
    auto it = m_components.find(hashCode);
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
    ASSERT_IS_BASE_OF(Component, TComponent);

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
    ASSERT_IS_BASE_OF(Component, TComponent);

    auto component = getComponent<TComponent>();
    if (!component)
    {
        return false;
    }

    component->disable();

    return true;
}

#endif // __ENTITY_TPP__
