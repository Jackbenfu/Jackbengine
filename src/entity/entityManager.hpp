//
// entityManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include <map>
#include "entity.hpp"
#include "component/componentCollection.hpp"

namespace Jackbengine {

class EntityManager
{
DISALLOW_COPY_AND_MOVE(EntityManager)

public:
    EntityManager() = default;
    ~EntityManager() = default;

    Entity addEntity();
    void removeEntity(Entity entity);
    bool isEntityEnabled(Entity entity) const;
    void enableEntity(Entity entity, bool enable);
    ComponentCollection& getEntity(Entity entity) const;

    template<typename TComponent, typename ...Args>
    TComponent *addComponent(Entity entity, Args&& ...args);

    template<typename TComponent>
    TComponent *getComponent(Entity entity) const;

    template<typename TComponent>
    bool hasComponent(Entity entity);

    template<typename TComponent>
    void enableComponent(Entity entity, bool enable);

private:
    std::pair<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity entity);
    const std::pair<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity entity) const;

    template<typename T>
    static auto findEntity(T& t, Entity entity) -> decltype(t.findEntity(entity));

    std::map<Entity, std::pair<bool, std::unique_ptr<ComponentCollection>>> m_entities;
};

template<typename TComponent, typename ...Args>
TComponent *EntityManager::addComponent(Entity entity, Args&& ...args)
{
    auto&[_, components] = findEntity(entity);

    return components->add<TComponent>(std::forward<Args>(args)...);
}

template<typename TComponent>
TComponent *EntityManager::getComponent(Entity entity) const
{
    auto&[_, components] = findEntity(entity);

    return components->get<TComponent>();
}

template<typename TComponent>
bool EntityManager::hasComponent(Entity entity)
{
    auto&[_, components] = findEntity(entity);

    return components->any<TComponent>();
}

template<typename TComponent>
void EntityManager::enableComponent(Entity entity, bool enable)
{
    auto&[_, components] = findEntity(entity);

    components->enable<TComponent>(enable);
}

template<typename T>
auto EntityManager::findEntity(T& t, Entity entity) -> decltype(t.findEntity(entity))
{
    auto it = t.m_entities.find(entity);
    if (it == t.m_entities.end())
    {
        throw std::runtime_error("Entity does not exist: " + std::to_string(entity));
    }

    return it->second;
}

}

#endif // __ENTITY_MANAGER_H__
