//
// entityCollection.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_COLLECTION_H__
#define __ENTITY_COLLECTION_H__

#include "component/componentCollection.hpp"

namespace Jackbengine {

using Entity = size_t;

class EntityCollection
{
    DISALLOW_COPY_AND_MOVE(EntityCollection)

public:
    EntityCollection() = default;
    ~EntityCollection() = default;

    Entity add();
    void remove(Entity entity);

    bool isEnabled(Entity entity) const;
    void enable(Entity entity);
    void disable(Entity entity);

    template<typename TComponent, typename... Args>
    void add(Entity entity, Args&&... args);

private:
    std::tuple<bool, std::unique_ptr<ComponentCollection>>& find(Entity entity);
    const std::tuple<bool, std::unique_ptr<ComponentCollection>>& find(Entity entity) const;

    template<typename T>
    static auto find(T& t, Entity entity) -> decltype(t.find(entity));

    std::unordered_map<size_t, std::tuple<bool, std::unique_ptr<ComponentCollection>>> m_entities;
};

#include "entityCollection.tpp"

} // namespace Jackbengine

#endif // __ENTITY_COLLECTION_H__
