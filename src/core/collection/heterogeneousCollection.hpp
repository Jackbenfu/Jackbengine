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
    TItem& get() const;

    template<typename TItem>
    bool any() const;

    template<typename TItem, typename ...Args>
    void add(Args&& ...args);

    template<typename TItem>
    void remove();

    template<typename TItem>
    void enable();

    template<typename TItem>
    void disable();

    template<typename TFunction>
    void apply(TFunction function);

private:
    template<typename TItem>
    auto& find() const;

    std::unordered_map<size_t, std::tuple<bool, std::unique_ptr<TBase>>> m_collection;
};

template<typename TBase>
template<typename TItem>
TItem& HeterogeneousCollection<TBase>::get() const
{
    ASSERT_IS_BASE_OF(TBase, TItem);

    const auto& tuple = find<TItem>();

    return dynamic_cast<TItem&>(*std::get<1>(tuple));
}

template<typename TBase>
template<typename TItem>
bool HeterogeneousCollection<TBase>::any() const
{
    ASSERT_IS_BASE_OF(TBase, TItem);

    const auto typeId = GET_TYPE_ID(TItem);

    return m_collection.find(typeId) != m_collection.end();
}

template<typename TBase>
template<typename TItem, typename ...Args>
void HeterogeneousCollection<TBase>::add(Args&& ...args)
{
    ASSERT_IS_BASE_OF(TBase, TItem);

    if (any<TItem>())
    {
        throw std::runtime_error(
            std::string("Item already exists: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    const auto typeId = GET_TYPE_ID(TItem);

    m_collection[typeId] = std::make_tuple(
        true,
        std::make_unique<TItem>(std::forward<Args>(args)...)
    );
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::remove()
{
    ASSERT_IS_BASE_OF(TBase, TItem);

    const auto typeId = GET_TYPE_ID(TItem);

    m_collection.erase(typeId);
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::enable()
{
    ASSERT_IS_BASE_OF(TBase, TItem);

    const auto& tuple = find<TItem>();

    std::get<0>(tuple) = true;
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::disable()
{
    ASSERT_IS_BASE_OF(TBase, TItem);

    const auto& tuple = find<TItem>();

    std::get<0>(tuple) = false;
}

template<typename TBase>
template<typename TFunction>
void HeterogeneousCollection<TBase>::apply(TFunction function)
{
    for (auto& pair : m_collection)
    {
        const auto& tuple = pair.second;

        const auto isEnabled = std::get<0>(tuple);
        if (!isEnabled)
        {
            continue;
        }

        auto& item = *std::get<1>(tuple);
        function(item);
    }
}

template<typename TBase>
template<typename TItem>
auto& HeterogeneousCollection<TBase>::find() const
{
    const auto typeId = GET_TYPE_ID(TItem);

    const auto it = m_collection.find(typeId);
    if (it == m_collection.end())
    {
        throw std::runtime_error(
            std::string("Item does not exist: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    if (!std::get<0>(it->second))
    {
        throw std::runtime_error(
            std::string("Item is disabled: ") + std::string(GET_TYPE_NAME(TItem))
        );
    }

    return it->second;
}

} // namespace Jackbengine

#endif // __HETEROGENEOUS_COLLECTION_H__
