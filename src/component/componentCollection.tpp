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

    const auto typeId = GET_TYPE_ID(TComponent);

    m_components[typeId] = std::make_tuple(
        true,
        std::make_unique<TComponent>(std::forward<Args>(args)...)
    );
}

template<typename TComponent>
TComponent& ComponentCollection::get()
{
    ASSERT_IS_BASE_OF(Jackbengine::Component2, TComponent);

    auto& tuple = find<TComponent>();

    return dynamic_cast<TComponent&>(*std::get<1>(tuple));
}

template<typename TComponent>
void ComponentCollection::remove()
{
    ASSERT_IS_BASE_OF(Jackbengine::Component2, TComponent);

    const auto typeId = GET_TYPE_ID(TComponent);

    m_components.erase(typeId);
}

template<typename TComponent>
void ComponentCollection::enable()
{
    ASSERT_IS_BASE_OF(Jackbengine::Component2, TComponent);

    auto& tuple = find<TComponent>();

    std::get<0>(tuple) = true;
}

template<typename TComponent>
void ComponentCollection::disable()
{
    ASSERT_IS_BASE_OF(Jackbengine::Component2, TComponent);

    auto& tuple = find<TComponent>();

    std::get<0>(tuple) = false;
}

template<typename TComponent>
auto& ComponentCollection::find()
{
    const auto typeId = GET_TYPE_ID(TComponent);

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
    const auto typeId = GET_TYPE_ID(TComponent);

    return m_components.find(typeId) != m_components.end();
}

#endif // __COMPONENT_COLLECTION_TPP__
