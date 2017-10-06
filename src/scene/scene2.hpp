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
    void enableEntity(Entity2 entity, bool enable);
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
    void enableComponent(Entity2 entity, bool enable);

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
    TSystem& getSystem();

    template<typename TSystem>
    void enableSystem();

    template<typename TSystem>
    void enableSystem(bool enable);

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

template<typename TComponent, typename ...Args>
void Scene2::addComponent(Entity2 entity, Args&& ...args)
{
    m_entityManager.addComponent<TComponent>(entity, std::forward<Args>(args)...);
    m_systemManager.addEntity(entity);
}

template<typename TComponent>
void Scene2::removeComponent(Entity2 entity)
{
    m_entityManager.removeComponent<TComponent>(entity);
    m_systemManager.removeEntity(entity, true);
}

template<typename TComponent>
TComponent& Scene2::getComponent(Entity2 entity) const
{
    return m_entityManager.getComponent<TComponent>(entity);
}

template<typename TComponent>
void Scene2::enableComponent(Entity2 entity)
{
    enableComponent<TComponent>(entity, true);
}

template<typename TComponent>
void Scene2::enableComponent(Entity2 entity, bool enable)
{
    m_entityManager.enableComponent<TComponent>(entity, enable);
    if (enable)
    {
        m_systemManager.addEntity(entity);
    }
    else
    {
        m_systemManager.removeEntity(entity, true);
    }
}

template<typename TComponent>
void Scene2::disableComponent(Entity2 entity)
{
    enableComponent<TComponent>(entity, false);
}

template<typename TSystem, typename ...Args>
void Scene2::addSystem(Args&& ...args)
{
    m_systemManager.addSystem<TSystem>(std::forward<Args>(args)...);
}

template<typename TSystem>
void Scene2::removeSystem()
{
    m_systemManager.removeSystem<TSystem>();
}

template<typename TSystem>
TSystem& Scene2::getSystem()
{
    return m_systemManager.getSystem<TSystem>();
}

template<typename TSystem>
void Scene2::enableSystem()
{
    enableSystem<TSystem>(true);
}

template<typename TSystem>
void Scene2::enableSystem(bool enable)
{
    m_systemManager.enableSystem<TSystem>(enable);
}

template<typename TSystem>
void Scene2::disableSystem()
{
    enableSystem<TSystem>(false);
}

template<typename TScene>
void Scene2::loadScene()
{
    static_assert(std::is_base_of<Scene2, TScene>::value);

    m_sceneManager.loadScene<TScene>(m_application, m_sceneManager);
}

} // namespace Jackbengine

#endif // __SCENE_2_H__
