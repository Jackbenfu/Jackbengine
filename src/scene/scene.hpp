//
// scene.hpp
// jackbengine
//
// Created by Damien Bendejacq on 18/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_H__
#define __SCENE_H__

#include "common.hpp"
#include "ecs/ecsManager.hpp"

#include "core/render/cursor.hpp"
#include "core/input/input.hpp"
#include "core/render/renderer.hpp"
#include "core/render/window.hpp"
#include "core/time/timer.hpp"

namespace Jackbengine {

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

    template<typename TComponent> TComponent* getComponent(Entity *entity);
    template<typename TComponent> TComponent* addComponent(Entity *entity);
    template<typename TComponent> bool setComponent(Entity *entity, TComponent *component);
    template<typename TComponent, typename TParam> TComponent* addComponent(Entity *entity, TParam param);
    template<typename TComponent> void removeComponent(Entity *entity);
    template<typename TComponent> void enableComponent(Entity *entity);
    template<typename TComponent> void disableComponent(Entity *entity);

    template<typename TSystem> TSystem* getSystem();
    template<typename TSystem> TSystem* addSystem();
    template<typename TSystem> void enableSystem();
    template<typename TSystem> void disableSystem();

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

    virtual const char* name() = 0;

protected:
    Scene();
    virtual ~Scene();

    virtual void frame(float delta) = 0;
    virtual bool initContents() = 0;

private:
    bool init();
    void loop();
    bool running() const;

    void clear();

    EcsManager *m_ecsManager = nullptr;

    Cursor *m_cursor = nullptr;
    Input *m_input = nullptr;
    Renderer *m_renderer = nullptr;
    Timer *m_timer = nullptr;
    Window *m_window = nullptr;

    bool m_running {false};
    const char *m_nextScene = nullptr;
};

#include "scene.tpp"

} // namespace Jackbengine

#endif // __SCENE_H__
