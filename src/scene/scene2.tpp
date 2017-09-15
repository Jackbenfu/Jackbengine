//
// scene2.tpp
// jackbengine
//
// Created by Damien Bendejacq on 16/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_2_TPP__
#define __SCENE_2_TPP__

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
    m_systemManager.removeEntity(entity);
}

template<typename TComponent>
TComponent& Scene2::getComponent(Entity2 entity) const
{
    return m_entityManager.getComponent<TComponent>(entity);
}

template<typename TComponent>
void Scene2::enableComponent(Entity2 entity)
{
    m_entityManager.enableComponent<TComponent>(entity);
    m_systemManager.addEntity(entity);
}

template<typename TComponent>
void Scene2::disableComponent(Entity2 entity)
{
    m_entityManager.removeComponent<TComponent>(entity);
    m_systemManager.removeEntity(entity);
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
void Scene2::enableSystem()
{
    m_systemManager.enableSystem<TSystem>();
}

template<typename TSystem>
void Scene2::disableSystem()
{
    m_systemManager.disableSystem<TSystem>();
}

template<typename TScene>
void Scene2::loadScene()
{
    ASSERT_IS_BASE_OF(Scene2, TScene);

    m_sceneManager.loadScene<TScene>(m_application, m_sceneManager);
}

#endif // __SCENE_2_TPP__
