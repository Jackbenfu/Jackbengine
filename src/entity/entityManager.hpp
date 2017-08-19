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
    void enableEntity(Entity2 entity);
    void disableEntity(Entity2 entity);
    ComponentCollection& getEntity(Entity2 entity) const;

    template<typename TComponent, typename... Args>
    void addComponent(Entity2 entity, Args&&... args);

    template<typename TComponent>
    void removeComponent(Entity2 entity);

    template<typename TComponent>
    TComponent& getComponent(Entity2 entity) const;

    template<typename TComponent>
    void enableComponent(Entity2 entity);

    template<typename TComponent>
    void disableComponent(Entity2 entity);

private:
    std::tuple<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity2 entity);
    const std::tuple<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity2 entity) const;

    template<typename T>
    static auto findEntity(T& t, Entity2 entity) -> decltype(t.findEntity(entity));

    std::unordered_map<size_t, std::tuple<bool, std::unique_ptr<ComponentCollection>>> m_entities;
};

#include "entityManager.tpp"

} // namespace Jackbengine

#endif // __ENTITY_MANAGER_H__
