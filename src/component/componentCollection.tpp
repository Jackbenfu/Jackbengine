//
// componentCollection.tpp
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COMPONENT_COLLECTION_TPP__
#define __COMPONENT_COLLECTION_TPP__

template<typename TComponent, typename ...Args>
void ComponentCollection::add(Args&& ...args)
{
    m_components.add<TComponent>(std::forward<Args>(args)...);
}

template<typename TComponent>
TComponent& ComponentCollection::get() const
{
    return m_components.get<TComponent>();
}

template<typename TComponent>
bool ComponentCollection::any() const
{
    return m_components.any<TComponent>();
}

template<typename TComponent>
void ComponentCollection::remove()
{
    m_components.remove<TComponent>();
}

template<typename TComponent>
void ComponentCollection::enable()
{
    m_components.enable<TComponent>();
}

template<typename TComponent>
void ComponentCollection::disable()
{
    m_components.disable<TComponent>();
}

#endif // __COMPONENT_COLLECTION_TPP__
