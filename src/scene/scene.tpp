//
// scene.tpp
// jackbengine
//
// Created by Damien Bendejacq on 29/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_TPP__
#define __SCENE_TPP__

template<typename TComponent>
TComponent* Scene::getComponent(Entity *entity)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    return m_ecsManager->getComponent<TComponent>(entity);
}

template<typename TComponent>
TComponent* Scene::addComponent(Entity *entity)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    return m_ecsManager->addComponent<TComponent>(entity);
}

template<typename TComponent>
bool Scene::setComponent(Entity *entity, TComponent *component)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    return m_ecsManager->setComponent(entity, component);
}

template<typename TComponent, typename TParam>
TComponent* Scene::addComponent(Entity *entity, TParam param)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    return m_ecsManager->addComponent<TComponent>(entity, param);
};

template<typename TComponent>
void Scene::removeComponent(Entity *entity)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    m_ecsManager->removeComponent<TComponent>(entity);
    m_ecsManager->removeEntity(entity);
}

template<typename TComponent>
void Scene::enableComponent(Entity *entity)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    m_ecsManager->enableComponent<TComponent>(entity);
}

template<typename TComponent>
void Scene::disableComponent(Entity *entity)
{
    ASSERT_IS_BASE_OF(Component, TComponent);

    m_ecsManager->disableComponent<TComponent>(entity);
}

template<typename TSystem>
TSystem* Scene::getSystem()
{
    ASSERT_IS_BASE_OF(System, TSystem);

    return m_ecsManager->getSystem<TSystem>();
}

template<typename TSystem>
TSystem* Scene::addSystem()
{
    ASSERT_IS_BASE_OF(System, TSystem);

    return m_ecsManager->addSystem<TSystem>();
}

template<typename TSystem>
void Scene::enableSystem()
{
    ASSERT_IS_BASE_OF(System, TSystem);

    m_ecsManager->enableSystem<TSystem>();
}

template<typename TSystem>
void Scene::disableSystem()
{
    ASSERT_IS_BASE_OF(System, TSystem);

    m_ecsManager->disableSystem<TSystem>();
}

#endif // __SCENE_TPP__
