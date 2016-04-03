//
//  scene.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_H__
#define __SCENE_H__

#include "common.h"

#include "entity/entityManager.h"
#include "system/systemManager.h"

#include "core/render/cursor.h"
#include "core/input/input.h"
#include "core/render/renderer.h"
#include "core/render/window.h"
#include "core/time/timer.h"

NS_BEGIN_JKB

class Scene
{
    friend class Application;

public:
    virtual ~Scene();

protected:
    Scene();

    virtual void frame(float delta) = 0;
    virtual const char* name() = 0;
    virtual bool initContents() = 0;

    static Entity* addEntity(const char *name);
    static bool removeEntity(Entity *entity);
    static bool enableEntity(Entity *entity);
    static bool disableEntity(Entity *entity);

    template<typename C> static C* getComponent(Entity *entity);
    template<typename C> static C* addComponent(Entity *entity);
    template<typename C> static bool removeComponent(Entity *entity);
    template<typename C> static bool enableComponent(Entity *entity);
    template<typename C> static bool disableComponent(Entity *entity);

    template<typename S> static S* addSystem();
    template<typename S> static bool enableSystem();
    template<typename S> static bool disableSystem();

    static EntityManager* entityManager();
    static EntityManager* em();

    static SystemManager* systemManager();
    static SystemManager* sm();

    static Cursor* cursor();
    static Input* input();
    static Renderer* renderer();
    static Timer* timer();
    static Window* window();

    static bool loadScene(const char *name);
    static void exit();

private:
    bool init();
    void loop();
    bool running() const;

    static void reset();

    static EntityManager *s_entityManager;
    static SystemManager *s_systemManager;

    static Cursor *s_cursor;
    static Input *s_input;
    static Renderer *s_renderer;
    static Timer *s_timer;
    static Window *s_window;

    static bool s_running;
    static const char *s_nextScene;
};

template<typename T>
class TypedScene :
    public Scene,
    public TypedObject<T>
{
};

template<typename C>
C* Scene::getComponent(Entity *entity)
{
    return s_entityManager->getComponent<C>(entity);
}

template<typename C>
C* Scene::addComponent(Entity *entity)
{
    C* component = s_entityManager->addComponent<C>(entity);

    if (component)
    {
        s_systemManager->addEntity(entity);
    }

    return component;
}

template<typename C>
bool Scene::removeComponent(Entity *entity)
{
    return s_entityManager->removeComponent<C>(entity) &&
        s_systemManager->removeEntity(entity);
}

template<typename C>
bool Scene::enableComponent(Entity *entity)
{
    return s_entityManager->enableComponent<C>(entity) &&
        s_systemManager->enableEntity(entity);
}

template<typename C>
bool Scene::disableComponent(Entity *entity)
{
    return s_entityManager->disableComponent<C>(entity) &&
        s_systemManager->disableEntity(entity);
}

template<typename S>
S* Scene::addSystem()
{
    return s_systemManager->addSystem<S>();
}

template<typename S>
bool Scene::enableSystem()
{
    return s_systemManager->enableSystem<S>();
}

template<typename S>
bool Scene::disableSystem()
{
    return s_systemManager->disableSystem<S>();
}

NS_END_JKB

#endif // __SCENE_H__
