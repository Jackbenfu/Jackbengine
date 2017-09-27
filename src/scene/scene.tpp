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
    static_assert(std::is_base_of<Component, TComponent>::value);

    return m_ecsManager->getComponent<TComponent>(entity);
}

template<typename TComponent>
TComponent* Scene::addComponent(Entity *entity)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    return m_ecsManager->addComponent<TComponent>(entity);
}

template<typename TComponent>
bool Scene::setComponent(Entity *entity, TComponent *component)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    return m_ecsManager->setComponent(entity, component);
}

template<typename TComponent, typename TParam>
TComponent* Scene::addComponent(Entity *entity, TParam param)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    return m_ecsManager->addComponent<TComponent>(entity, param);
};

template<typename TComponent>
void Scene::removeComponent(Entity *entity)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    m_ecsManager->removeComponent<TComponent>(entity);
    m_ecsManager->removeEntity(entity);
}

template<typename TComponent>
void Scene::enableComponent(Entity *entity)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    m_ecsManager->enableComponent<TComponent>(entity);
}

template<typename TComponent>
void Scene::disableComponent(Entity *entity)
{
    static_assert(std::is_base_of<Component, TComponent>::value);

    m_ecsManager->disableComponent<TComponent>(entity);
}

template<typename TSystem>
TSystem* Scene::getSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    return m_ecsManager->getSystem<TSystem>();
}

template<typename TSystem>
TSystem* Scene::addSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    return m_ecsManager->addSystem<TSystem>();
}

template<typename TSystem>
void Scene::enableSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    m_ecsManager->enableSystem<TSystem>();
}

template<typename TSystem>
void Scene::disableSystem()
{
    static_assert(std::is_base_of<System, TSystem>::value);

    m_ecsManager->disableSystem<TSystem>();
}

#endif // __SCENE_TPP__
