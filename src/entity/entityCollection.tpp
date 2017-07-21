//
// entityCollection.tpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_COLLECTION_TPP__
#define __ENTITY_COLLECTION_TPP__

template<typename TComponent, typename... Args>
void EntityCollection::add(Entity entity, Args&&... args)
{
    auto& tuple = find(entity);

    std::get<1>(tuple)->add(std::forward<Args>(args)...);
}

template<typename T>
auto EntityCollection::find(T& t, Entity entity) -> decltype(t.find(entity))
{
    auto it = t.m_entities.find(entity);
    if (it == t.m_entities.end())
    {
        throw std::runtime_error("Entity does not exist: " + std::to_string(entity));
    }

    return it->second;
}

#endif // __ENTITY_COLLECTION_TPP__
