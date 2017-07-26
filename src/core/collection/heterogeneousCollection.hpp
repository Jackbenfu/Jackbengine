//
// heterogeneousCollection.hpp
// jackbengine
//
// Created by Damien Bendejacq on 26/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __HETEROGENEOUS_COLLECTION_H__
#define __HETEROGENEOUS_COLLECTION_H__

#include <unordered_map>

#include "common.hpp"

namespace Jackbengine {

template<typename TBase>
class HeterogeneousCollection
{
    DISALLOW_COPY_AND_MOVE(HeterogeneousCollection<TBase>)

public:
    HeterogeneousCollection() = default;
    ~HeterogeneousCollection() = default;

    template<typename TItem>
    TItem& get();

    template<typename TItem, typename... Args>
    void add(Args&&... args);

    template<typename TItem>
    void remove();

    template<typename TItem>
    void enable();

    template<typename TItem>
    void disable();

private:
    template<typename TItem>
    bool any();

    template<typename TItem>
    auto& find();

    std::unordered_map<size_t, std::tuple<bool, std::unique_ptr<TBase>>> m_collection;
};

#include "heterogeneousCollection.tpp"

} // namespace Jackbengine

#endif // __HETEROGENEOUS_COLLECTION_H__
