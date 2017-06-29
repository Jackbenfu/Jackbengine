//
// scene.h
// jackbengine
//
// Created by Damien Bendejacq on 18/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_H__
#define __SCENE_H__

#include "common.h"
#include "ecs/ecsManager.h"

#include "core/render/cursor.h"
#include "core/input/input.h"
#include "core/render/renderer.h"
#include "core/render/window.h"
#include "core/time/timer.h"

NS_BEGIN_JKB

class Scene
{
    friend class Application;
    friend class SceneLoader;

public:
    bool isEntityEnabled(Entity *entity) const;
    Entity* getEntity(const char *name) const;
    Entity* addEntity(const char *name);
    void removeEntity(Entity *entity);
    bool removeEntity(const char *name);
    void enableEntity(Entity *entity);
    void enableEntity(const char *name);
    void disableEntity(Entity *entity);
    void disableEntity(const char *name);

    template<typename C> C* getComponent(Entity *entity);
    template<typename C> C* addComponent(Entity *entity);
    template<typename C> bool setComponent(Entity *entity, C *component);
    template<typename C, typename Param> C* addComponent(Entity *entity, Param param);
    template<typename C> void removeComponent(Entity *entity);
    template<typename C> void enableComponent(Entity *entity);
    template<typename C> void disableComponent(Entity *entity);

    template<typename S> S* getSystem();
    template<typename S> S* addSystem();
    template<typename S> void enableSystem();
    template<typename S> void disableSystem();

    Cursor* cursor() const;
    void setCursor(Cursor *cursor);

    Input* input() const;
    void setInput(Input *input);

    Renderer* renderer() const;
    void setRenderer(Renderer *renderer);

    Timer* timer() const;
    void setTimer(Timer *timer);

    Window* window() const;
    void setWindow(Window *window);

    bool loadScene(const char *name);
    void exit();

protected:
    Scene();
    virtual ~Scene();

    virtual void frame(float delta) = 0;
    virtual const char* name() = 0;
    virtual bool initContents() = 0;

private:
    bool init();
    void loop();
    bool running() const;

    void clear();

    EcsManager *m_ecsManager {nullptr};

    Cursor *m_cursor {nullptr};
    Input *m_input {nullptr};
    Renderer *m_renderer {nullptr};
    Timer *m_timer {nullptr};
    Window *m_window {nullptr};

    bool m_running {false};
    const char *m_nextScene {nullptr};
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
    return m_ecsManager->getComponent<C>(entity);
}

template<typename C>
C* Scene::addComponent(Entity *entity)
{
    return m_ecsManager->addComponent<C>(entity);
}

template<typename C>
bool Scene::setComponent(Entity *entity, C *component)
{
    return m_ecsManager->setComponent(entity, component);
}

template<typename C, typename Param>
C* Scene::addComponent(Entity *entity, Param param)
{
    return m_ecsManager->addComponent<C>(entity, param);
};

template<typename C>
void Scene::removeComponent(Entity *entity)
{
    m_ecsManager->removeComponent<C>(entity);
    m_ecsManager->removeEntity(entity);
}

template<typename C>
void Scene::enableComponent(Entity *entity)
{
    m_ecsManager->enableComponent<C>(entity);
}

template<typename C>
void Scene::disableComponent(Entity *entity)
{
    m_ecsManager->disableComponent<C>(entity);
}

template<typename S>
S* Scene::getSystem()
{
    return m_ecsManager->getSystem<S>();
}

template<typename S>
S* Scene::addSystem()
{
    return m_ecsManager->addSystem<S>();
}

template<typename S>
void Scene::enableSystem()
{
    m_ecsManager->enableSystem<S>();
}

template<typename S>
void Scene::disableSystem()
{
    m_ecsManager->disableSystem<S>();
}

NS_END_JKB

#endif // __SCENE_H__
