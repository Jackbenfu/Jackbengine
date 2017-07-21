//
// componentCollection.tpp
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COMPONENT_COLLECTION_TPP__
#define __COMPONENT_COLLECTION_TPP__

template<typename TComponent, typename... Args>
void ComponentCollection::add(Args&&... args)
{
    ASSERT_IS_BASE_OF(Jackbengine::Component2, TComponent);

    if (any<TComponent>())
    {
        throw std::runtime_error(
            std::string("Component already exists: ") + std::string(GET_TYPE_NAME(TComponent))
        );
    }

    auto typeId = GET_TYPE_ID(TComponent);

    m_components[typeId] = std::make_tuple(
        true,
        std::make_unique<TComponent>(std::forward<Args>(args)...)
    );
}

template<typename TComponent>
TComponent& ComponentCollection::get()
{
    return std::get<1>(find<TComponent>());
}

template<typename TComponent>
auto& ComponentCollection::find()
{
    auto typeId = GET_TYPE_ID(TComponent);

    auto it = m_components.find(typeId);
    if (it == m_components.end())
    {
        throw std::runtime_error(
            std::string("Component does not exist: ") + std::string(GET_TYPE_NAME(TComponent))
        );
    }

    return it->second;
}

template<typename TComponent>
bool ComponentCollection::any()
{
    auto typeId = GET_TYPE_ID(TComponent);

    return m_components.find(typeId) != m_components.end();
}

#endif // __COMPONENT_COLLECTION_TPP__
