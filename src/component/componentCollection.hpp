//
// componentCollection.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COMPONENT_COLLECTION_H__
#define __COMPONENT_COLLECTION_H__

#include <string>
#include <unordered_map>
#include <tuple>

#include "component/component2.hpp"

namespace Jackbengine {

class ComponentCollection
{
    DISALLOW_COPY_AND_MOVE(ComponentCollection)

public:
    ComponentCollection();
    ~ComponentCollection();

    template<typename TComponent, typename... Args>
    void add(Args&&... args);

    template<typename TComponent>
    TComponent& get();

private:
    template<typename TComponent>
    auto& find();

    template<typename TComponent>
    bool any();

    std::unordered_map<size_t, std::tuple<bool, std::unique_ptr<Component2>>> m_components;
};

#include "componentCollection.tpp"

} // namespace Jackbengine

#endif // __COMPONENT_COLLECTION_H__
