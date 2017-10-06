//
// entityManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "component/componentCollection.hpp"

namespace Jackbengine {

using Entity2 = size_t;

class EntityManager
{
    DISALLOW_COPY_AND_MOVE(EntityManager)

public:
    EntityManager() = default;
    ~EntityManager() = default;

    Entity2 addEntity();
    void removeEntity(Entity2 entity);
    bool isEntityEnabled(Entity2 entity) const;
    void enableEntity(Entity2 entity, bool enable);
    ComponentCollection& getEntity(Entity2 entity) const;

    template<typename TComponent, typename ...Args>
    void addComponent(Entity2 entity, Args&& ...args);

    template<typename TComponent>
    void removeComponent(Entity2 entity);

    template<typename TComponent>
    TComponent& getComponent(Entity2 entity) const;

    template<typename TComponent>
    void enableComponent(Entity2 entity, bool enable);

private:
    std::tuple<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity2 entity);
    const std::tuple<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity2 entity) const;

    template<typename T>
    static auto findEntity(T& t, Entity2 entity) -> decltype(t.findEntity(entity));

    std::map<Entity2, std::tuple<bool, std::unique_ptr<ComponentCollection>>> m_entities;

};

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

    return componentCollection->get<TComponent>();
}

template<typename TComponent>
void EntityManager::enableComponent(Entity2 entity, bool enable)
{
    auto& tuple = findEntity(entity);

    std::get<1>(tuple)->enable<TComponent>(enable);
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

} // namespace Jackbengine

#endif // __ENTITY_MANAGER_H__
