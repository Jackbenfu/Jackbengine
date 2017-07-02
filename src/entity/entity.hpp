//
// entity.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include "common.hpp"
#include "component/component.hpp"

namespace Jackbengine {

class Entity
{
    friend class EcsManager;

public:
    bool isEnabled() const;

    template<typename TComponent> TComponent* getComponent(bool returnIfDisabled = true);
    template<typename TComponent> TComponent* getComponentIfEnabled();

private:
    explicit Entity(const char *name);
    ~Entity();

    void enable();
    void disable();

    template<typename TComponent> TComponent* addComponent();
    template<typename TComponent, typename TParam> TComponent* addComponent(TParam param);
    template<typename TComponent> bool setComponent(TComponent *component);
    template<typename TComponent> bool removeComponent();
    template<typename TComponent> bool enableComponent();
    template<typename TComponent> bool disableComponent();

    std::map<size_t, Component*> m_components;
    bool m_enabled {true};
};

#include "entity.tpp"

} // namespace Jackbengine

#endif // __ENTITY_H__
