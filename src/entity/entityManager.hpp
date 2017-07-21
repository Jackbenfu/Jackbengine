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

    // Entity
    Entity2 add();
    void remove(Entity2 entity);
    bool isEnabled(Entity2 entity) const;
    void enable(Entity2 entity);
    void disable(Entity2 entity);

    // Component
    template<typename TComponent, typename... Args>
    void add(Entity2 entity, Args&&... args);

    template<typename TComponent>
    TComponent& get(Entity2 entity);

    template<typename TComponent>
    void remove(Entity2 entity);

    template<typename TComponent>
    void enable(Entity2 entity);

    template<typename TComponent>
    void disable(Entity2 entity);

private:
    std::tuple<bool, std::unique_ptr<ComponentCollection>>& find(Entity2 entity);
    const std::tuple<bool, std::unique_ptr<ComponentCollection>>& find(Entity2 entity) const;

    template<typename T>
    static auto find(T& t, Entity2 entity) -> decltype(t.find(entity));

    std::unordered_map<size_t, std::tuple<bool, std::unique_ptr<ComponentCollection>>> m_entities;
};

#include "entityManager.tpp"

} // namespace Jackbengine

#endif // __ENTITY_MANAGER_H__
