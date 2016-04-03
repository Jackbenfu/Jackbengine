//
//  scene.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "scene.h"

EntityManager *Scene::s_entityManager = new EntityManager();
SystemManager *Scene::s_systemManager = new SystemManager(s_entityManager);

Cursor *Scene::s_cursor = nullptr;
Input *Scene::s_input = nullptr;
Renderer *Scene::s_renderer = nullptr;
Timer *Scene::s_timer = nullptr;
Window *Scene::s_window = nullptr;

bool Scene::s_running = false;
const char *Scene::s_nextScene = nullptr;

Scene::Scene()
{
}

Scene::~Scene()
{
    reset();

    DELETE_SAFE(s_systemManager);
    DELETE_SAFE(s_entityManager);
}

Entity* Scene::addEntity(const char *name)
{
    Entity *entity = s_entityManager->addEntity(name);

    if (entity)
    {
        s_systemManager->addEntity(entity);
    }

    return entity;
}

bool Scene::removeEntity(Entity *entity)
{
    return s_entityManager->removeEntity(entity) &&
        s_systemManager->removeEntity(entity);
}

bool Scene::enableEntity(Entity *entity)
{
    return s_entityManager->enableEntity(entity) &&
        s_systemManager->enableEntity(entity);
}

bool Scene::disableEntity(Entity *entity)
{
    return s_entityManager->disableEntity(entity) &&
        s_systemManager->disableEntity(entity);
}

bool Scene::loadScene(const char *name)
{
    if (name && !s_nextScene)
    {
        s_nextScene = name;
        return true;
    }

    return false;
}

void Scene::exit()
{
    s_running = false;
}

bool Scene::init()
{
    s_running = initContents();

    return s_running;
}

void Scene::loop()
{
    s_timer->start();
    float delta = s_timer->getElapsedMilliseconds() * 0.001f;

    s_renderer->clear();
    s_input->update(delta);
    s_systemManager->update(delta);

    frame(delta);

    s_renderer->present();

    if (s_input->quit())
    {
        exit();
    }

    s_timer->snapshot();
}

bool Scene::running() const
{
    return s_running;
}

EntityManager* Scene::entityManager()
{
    return s_entityManager;
}

EntityManager* Scene::em()
{
    return s_entityManager;
}

SystemManager* Scene::systemManager()
{
    return s_systemManager;
}

SystemManager* Scene::sm()
{
    return s_systemManager;
}

Cursor* Scene::cursor()
{
    return s_cursor;
}

Input* Scene::input()
{
    return s_input;
}

Renderer* Scene::renderer()
{
    return s_renderer;
}

Timer* Scene::timer()
{
    return s_timer;
}

Window* Scene::window()
{
    return s_window;
}

void Scene::reset()
{
    if (s_systemManager)
    {
        s_systemManager->clear();
    }

    if (s_entityManager)
    {
        s_entityManager->clear();
    }
}
