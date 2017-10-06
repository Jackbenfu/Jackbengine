//
// scene2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "scene2.hpp"

using namespace Jackbengine;

Scene2::Scene2(Application2& application, SceneManager<Scene2>& sceneManager)
    : m_application {application},
      m_sceneManager {sceneManager},
      m_systemManager {m_entityManager}
{ }

Entity2 Scene2::addEntity()
{
    return m_entityManager.addEntity();
}

void Scene2::removeEntity(Entity2 entity)
{
    m_entityManager.removeEntity(entity);
    m_systemManager.removeEntity(entity, false);
}

void Scene2::enableEntity(Entity2 entity)
{
    enableEntity(entity, true);
}

void Scene2::enableEntity(Entity2 entity, bool enable)
{
    m_entityManager.enableEntity(entity, enable);

    if (enable)
    {
        m_systemManager.addEntity(entity);
    }
    else
    {
        m_systemManager.removeEntity(entity, false);
    }
}

void Scene2::disableEntity(Entity2 entity)
{
    enableEntity(entity, false);
}

void Scene2::update(float delta)
{
    m_systemManager.frame(delta);
    frame(delta);
    m_sceneManager.trySetNextScene();
}

Timer2& Scene2::timer() const
{
    return m_application.timer();
}

Cursor2& Scene2::cursor() const
{
    return m_application.cursor();
}

Input2& Scene2::input() const
{
    return m_application.input();
}

Window2& Scene2::window() const
{
    return m_application.window();
}

Renderer2& Scene2::renderer() const
{
    return m_application.renderer();
}

void Scene2::exitApplication()
{
    m_application.exit();
}

void Scene2::frame(float)
{ }
