//
// scene2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_2_H__
#define __SCENE_2_H__

#include "sceneManager.hpp"
#include "application/application2.hpp"
#include "entity/entityManager.hpp"
#include "system/systemManager.hpp"

namespace Jackbengine {

class Scene2
{
    DISALLOW_COPY_AND_MOVE(Scene2)

public:
    Scene2(Application2& application, SceneManager<Scene2>& sceneManager);
    virtual ~Scene2() = default;

    /*
     * Entity
     */
    Entity2 addEntity();
    void removeEntity(Entity2 entity);
    void enableEntity(Entity2 entity);
    void disableEntity(Entity2 entity);

    /*
     * Component
     */
    template<typename TComponent, typename ...Args>
    void addComponent(Entity2 entity, Args&& ...args);

    template<typename TComponent>
    void removeComponent(Entity2 entity);

    template<typename TComponent>
    TComponent& getComponent(Entity2 entity) const;

    template<typename TComponent>
    void enableComponent(Entity2 entity);

    template<typename TComponent>
    void disableComponent(Entity2 entity);

    /*
     * System
     */
    template<typename TSystem, typename ...Args>
    void addSystem(Args&& ...args);

    template<typename TSystem>
    void removeSystem();

    template<typename TSystem>
    void enableSystem();

    template<typename TSystem>
    void disableSystem();

    void update(float delta);

    Timer2& timer() const;
    Cursor2& cursor() const;
    Input2& input() const;
    Window2& window() const;
    Renderer2& renderer() const;

    void exitApplication();

    template<typename TScene>
    void loadScene();

private:
    virtual void frame(float delta);

    Application2& m_application;
    SceneManager<Scene2>& m_sceneManager;
    EntityManager m_entityManager;
    SystemManager m_systemManager;
};

#include "scene2.tpp"

} // namespace Jackbengine

#endif // __SCENE_2_H__
