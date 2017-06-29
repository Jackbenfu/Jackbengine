//
// scene.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "scene.h"
#include "application/application.h"

Scene::Scene()
{
}

Scene::~Scene()
{
    clear();
}

bool Scene::isEntityEnabled(Entity *entity) const
{
    return m_ecsManager->isEntityEnabled(entity);
}

Entity* Scene::getEntity(const char *name) const
{
    return m_ecsManager->getEntity(name);
}

Entity* Scene::addEntity(const char *name)
{
    return m_ecsManager->addEntity(name);
}

void Scene::removeEntity(Entity *entity)
{
    m_ecsManager->removeEntity(entity);
}

bool Scene::removeEntity(const char *name)
{
    return m_ecsManager->removeEntity(name);
}

void Scene::enableEntity(Entity *entity)
{
    m_ecsManager->enableEntity(entity);
}

void Scene::enableEntity(const char *name)
{
    m_ecsManager->enableEntity(name);
}

void Scene::disableEntity(Entity *entity)
{
    m_ecsManager->disableEntity(entity);
}

void Scene::disableEntity(const char *name)
{
    m_ecsManager->disableEntity(name);
}

bool Scene::loadScene(const char *name)
{
    if (name && !m_nextScene)
    {
        m_nextScene = name;
        return true;
    }

    return false;
}

void Scene::exit()
{
    m_running = false;
}

bool Scene::init()
{
    m_ecsManager = new EcsManager();
    m_running = initContents();

    return m_running;
}

void Scene::loop()
{
    timer()->start();
    float delta = timer()->getElapsedMilliseconds() * 0.001f;

    renderer()->clear();
    input()->update(delta);
    m_ecsManager->update(delta);

    frame(delta);

    renderer()->present();

    if (input()->quit())
    {
        exit();
    }

    timer()->snapshot();
}

bool Scene::running() const
{
    return m_running;
}

Cursor* Scene::cursor() const
{
    return m_cursor;
}

void Scene::setCursor(Cursor *cursor)
{
    m_cursor = cursor;
}

Input* Scene::input() const
{
    return m_input;
}

void Scene::setInput(Input *input)
{
    m_input = input;
}

Renderer* Scene::renderer() const
{
    return m_renderer;
}

void Scene::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}

Timer* Scene::timer() const
{
    return m_timer;
}

void Scene::setTimer(Timer *timer)
{
    m_timer = timer;
}

Window* Scene::window() const
{
    return m_window;
}

void Scene::setWindow(Window *window)
{
    m_window = window;
}

void Scene::clear()
{
    if (m_ecsManager)
    {
        m_ecsManager->clear();
    }

    DELETE_SAFE(m_ecsManager);
}
