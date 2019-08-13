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
#include <string>
#include <memory>
#include "common.hpp"

namespace Jackbengine {

template<typename TBase>
class HeterogeneousCollection
{
public:
    HeterogeneousCollection() = default;
    ~HeterogeneousCollection() = default;

    template<typename TItem>
    TItem *get() const;

    template<typename TItem>
    bool any() const;

    template<typename TItem, typename ...Args>
    TItem *add(Args &&...args);

    template<typename TItem>
    void remove();

    template<typename TItem>
    void enable(bool enable);

    template<typename TFunction>
    void apply(TFunction function);

private:
    template<typename TItem>
    std::pair<bool, std::unique_ptr<TBase>> &find();
    template<typename TItem>
    const std::pair<bool, std::unique_ptr<TBase>> &find() const;

    std::unordered_map<size_t, std::pair<bool, std::unique_ptr<TBase>>> m_collection;
};

template<typename TBase>
template<typename TItem>
TItem *HeterogeneousCollection<TBase>::get() const
{
    static_assert(std::is_base_of<TBase, TItem>::value);

    const auto&[enabled, item] = find<TItem>();
    if (!enabled)
    {
        throw std::runtime_error(
            std::string("Item is disabled: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    return dynamic_cast<TItem *>(item.get());
}

template<typename TBase>
template<typename TItem>
bool HeterogeneousCollection<TBase>::any() const
{
    static_assert(std::is_base_of<TBase, TItem>::value);

    const auto typeId = GET_TYPE_ID(TItem);
    const auto it = m_collection.find(typeId);

    return it != m_collection.end() && it->second.first;
}

template<typename TBase>
template<typename TItem, typename ...Args>
TItem *HeterogeneousCollection<TBase>::add(Args &&...args)
{
    static_assert(std::is_base_of<TBase, TItem>::value);

    if (any<TItem>())
    {
        throw std::runtime_error(
            std::string("Item already exists: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    const auto typeId = GET_TYPE_ID(TItem);

    m_collection[typeId] = std::make_tuple(
        true, std::make_unique<TItem>(std::forward<Args>(args)...)
    );

    return get<TItem>();
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::remove()
{
    static_assert(std::is_base_of<TBase, TItem>::value);

    const auto typeId = GET_TYPE_ID(TItem);

    m_collection.erase(typeId);
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::enable(bool enable)
{
    static_assert(std::is_base_of<TBase, TItem>::value);

    auto &pair = find<TItem>();

    pair.first = enable;
}

template<typename TBase>
template<typename TFunction>
void HeterogeneousCollection<TBase>::apply(TFunction function)
{
    for (auto&[type, item] : m_collection)
    {
        auto&[enabled, value] = item;

        if (!enabled)
        {
            continue;
        }

        function(value);
    }
}

template<typename TBase>
template<typename TItem>
std::pair<bool, std::unique_ptr<TBase>> &HeterogeneousCollection<TBase>::find()
{
    const auto typeId = GET_TYPE_ID(TItem);
    const auto it = m_collection.find(typeId);

    if (it == m_collection.end())
    {
        throw std::runtime_error(
            std::string("Item does not exist: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    return it->second;
}

template<typename TBase>
template<typename TItem>
const std::pair<bool, std::unique_ptr<TBase>> &HeterogeneousCollection<TBase>::find() const
{
    const auto typeId = GET_TYPE_ID(TItem);
    const auto it = m_collection.find(typeId);

    if (it == m_collection.end())
    {
        throw std::runtime_error(
            std::string("Item does not exist: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    return it->second;
}

}

#endif // __HETEROGENEOUS_COLLECTION_H__
