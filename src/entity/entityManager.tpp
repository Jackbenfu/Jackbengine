//
// entityManager.tpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_MANAGER_TPP__
#define __ENTITY_MANAGER_TPP__

template<typename TComponent, typename ...Args>
void EntityManager::addComponent(Entity2 entity, Args&& ...args)
{
    auto& tuple = findEntity(entity);

    std::get<1>(tuple)->add<TComponent>(std::forward<Args>(args)...);
}

template<typename TComponent>
void EntityManager::removeComponent(Entity2 entity)
{
    auto& tuple = findEntity(entity);

    std::get<1>(tuple)->remove<TComponent>();
}

template<typename TComponent>
TComponent& EntityManager::getComponent(Entity2 entity) const
{
    auto& tuple = findEntity(entity);
    auto& componentCollection = std::get<1>(tuple);

    return (TComponent&)componentCollection->get<TComponent>();
}

template<typename TComponent>
void EntityManager::enableComponent(Entity2 entity)
{
    auto& tuple = findEntity(entity);

    std::get<1>(tuple)->enable<TComponent>();
}

template<typename TComponent>
void EntityManager::disableComponent(Entity2 entity)
{
    auto& tuple = findEntity(entity);

    std::get<1>(tuple)->disable<TComponent>();
}

template<typename T>
auto EntityManager::findEntity(T& t, Entity2 entity) -> decltype(t.findEntity(entity))
{
    auto it = t.m_entities.find(entity);
    if (it == t.m_entities.end())
    {
        throw std::runtime_error("Entity does not exist: " + std::to_string(entity));
    }

    return it->second;
}

#endif // __ENTITY_MANAGER_TPP__
