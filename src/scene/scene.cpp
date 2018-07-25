//
// scene.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "scene.hpp"

using namespace Jackbengine;

Scene::Scene(Application& application, SceneManager<Scene>& sceneManager)
    : m_application {application},
      m_sceneManager {sceneManager},
      m_entityManager {std::make_unique<EntityManager>()},
      m_systemManager {std::make_unique<SystemManager>(*m_entityManager)}
{
}

Entity Scene::addEntity()
{
    return m_entityManager->addEntity();
}

void Scene::removeEntity(Entity entity)
{
    m_entityManager->removeEntity(entity);
    m_systemManager->removeEntity(entity, false);
}

void Scene::enableEntity(Entity entity)
{
    enableEntity(entity, true);
}

void Scene::enableEntity(Entity entity, bool enable)
{
    m_entityManager->enableEntity(entity, enable);

    if (enable)
    {
        m_systemManager->addEntity(entity);
    }
    else
    {
        m_systemManager->removeEntity(entity, false);
    }
}

void Scene::disableEntity(Entity entity)
{
    enableEntity(entity, false);
}

void Scene::update(float delta)
{
    m_systemManager->frame(delta);

    frame(delta);

    m_sceneManager.loadNextSceneIfRequired();
}

void Scene::exitApplication()
{
    m_application.exit();
}

void Scene::frame(float)
{
}
