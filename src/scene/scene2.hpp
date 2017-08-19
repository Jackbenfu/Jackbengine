//
// scene2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_2_H__
#define __SCENE_2_H__

#include "application/application2.hpp"
#include "entity/entityManager.hpp"
#include "system/systemManager.hpp"

namespace Jackbengine {

class Scene2
{
    DISALLOW_COPY_AND_MOVE(Scene2)

public:
    explicit Scene2(const Application2& application);

    virtual ~Scene2() = default;

    // Entity
    Entity2 addEntity();
    void removeEntity(Entity2 entity);
    void enableEntity(Entity2 entity);
    void disableEntity(Entity2 entity);

    // Component
    template<typename TComponent, typename... Args>
    void addComponent(Entity2 entity, Args&&... args);
    template<typename TComponent>
    void removeComponent(Entity2 entity);
    template<typename TComponent>
    TComponent& getComponent(Entity2 entity) const;
    template<typename TComponent>
    void enableComponent(Entity2 entity);
    template<typename TComponent>
    void disableComponent(Entity2 entity);

    // System
    template<typename TSystem, typename... Args>
    void addSystem(Args&&... args);
    template<typename TSystem>
    void removeSystem();
    template<typename TSystem>
    void enableSystem();
    template<typename TSystem>
    void disableSystem();

private:
    const Application2& m_application;
    EntityManager m_entityManager;
    SystemManager m_systemManager;
};

#include "scene2.tpp"

} // namespace Jackbengine

#endif // __SCENE_2_H__
