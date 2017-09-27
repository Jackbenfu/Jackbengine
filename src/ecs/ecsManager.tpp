//
// ecsManager.tpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ECS_MANAGER_TPP__
#define __ECS_MANAGER_TPP__

template<typename TComponent>
TComponent* EcsManager::getComponent(Entity *entity, bool returnIfDisabled) const
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return nullptr;
    }

    return entity->getComponent<TComponent>(returnIfDisabled);
}

template<typename TComponent>
TComponent* EcsManager::getComponentIfEnabled(Entity *entity) const
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    return getComponent<TComponent>(entity, false);
}

template<typename TComponent>
TComponent* EcsManager::addComponent(Entity *entity)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return nullptr;
    }

    auto component = entity->addComponent<TComponent>();
    if (nullptr == component)
    {
        return nullptr;
    }

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return component;
}

template<typename TComponent, typename TParam>
TComponent* EcsManager::addComponent(Entity *entity, TParam param)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return nullptr;
    }

    auto component = entity->addComponent<TComponent>(param);
    if (nullptr == component)
    {
        return nullptr;
    }

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return component;
}

template<typename TComponent>
bool EcsManager::setComponent(Entity *entity, TComponent *component)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return false;
    }

    auto result = entity->setComponent(component);

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return result;
}

template<typename TComponent>
bool EcsManager::removeComponent(Entity *entity) const
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return false;
    }

    if (!entity->removeComponent<TComponent>())
    {
        return false;
    }

    for (auto system : m_systems)
    {
        system->removeEntity(entity);
    }

    return true;
}

template<typename TComponent>
bool EcsManager::enableComponent(Entity *entity) const
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return false;
    }

    auto result = entity->enableComponent<TComponent>();

    for (auto system : m_systems)
    {
        system->addEntity(entity);
    }

    return result;
}

template<typename TComponent>
bool EcsManager::disableComponent(Entity *entity) const
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    if (!entity)
    {
        return false;
    }

    auto result = entity->disableComponent<TComponent>();

    for (auto system : m_systems)
    {
        system->removeEntity(entity);
    }

    return result;
}

template<typename TSystem>
TSystem* EcsManager::getSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    auto typeId = GET_TYPE_ID(TSystem);
    for (size_t i = 0; i < m_systemTypes.size(); ++i)
    {
        if (m_systemTypes[i] == typeId)
        {
            return static_cast<TSystem*>(m_systems[i]);
        }
    }

    return nullptr;
}

template<typename TSystem>
TSystem* EcsManager::addSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    auto freshlyAdded = false;

    auto system = getSystem<TSystem>();
    if (!system)
    {
        system = new TSystem();

        m_systemTypes.push_back(GET_TYPE_ID(TSystem));
        m_systems.push_back(system);

        freshlyAdded = true;
    }

    for (auto entity : m_entities)
    {
        system->addEntity(entity);
    }

    return freshlyAdded ? system : nullptr;
}

template<typename TSystem>
void EcsManager::removeSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    disableSystem<TSystem>();
}

template<typename TSystem>
void EcsManager::enableSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    auto system = getSystem<TSystem>();
    if (system)
    {
        system->enable();
    }
}

template<typename TSystem>
void EcsManager::disableSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    auto typeId = GET_TYPE_ID(TSystem);

    auto itType = find(m_systemTypes.begin(), m_systemTypes.end(), typeId);
    if (m_systemTypes.end() != itType)
    {
        m_systemTypes.erase(itType);
    }

    auto system = getSystem<TSystem>();
    auto itSystem = find(m_systems.begin(), m_systems.end(), system);
    if (m_systems.end() != itSystem)
    {
        DELETE_SAFE(*itSystem);
        m_systems.erase(itSystem);
    }
}

#endif // __ECS_MANAGER_TPP__
