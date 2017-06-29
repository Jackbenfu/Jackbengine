//
// application.h
// jackbengine
//
// Created by Damien Bendejacq on 10/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <map>
#include "applicationConfig.h"
#include "scene/scene.h"

NS_BEGIN_JKB
NS_STD

class Application
{
public:
    bool init();
    bool running() const;
    void loop();

protected:
    Application();
    virtual ~Application();

    virtual bool configure(ApplicationConfig& config) = 0;

    template<typename S>
    bool addScene();

private:
    Scene* getScene(const char *name);

    Scene *m_currentScene = nullptr;
    map<uint, Scene*> m_scenes;

    ApplicationConfig m_config;

    Cursor *m_cursor = nullptr;
    Input *m_input = nullptr;
    Renderer *m_renderer = nullptr;
    Timer *m_timer = nullptr;
    Window *m_window = nullptr;
};

template<typename S>
bool Application::addScene()
{
    uint type = S::getType();
    map<uint, Scene*>::const_iterator it = m_scenes.find(type);
    if (m_scenes.end() == it)
    {
        Scene *scene = new S();

        if (getScene(scene->name()))
        {
            DELETE_SAFE(scene);
            return false;
        }

        m_scenes.insert(make_pair(S::getType(), scene));

        scene->setCursor(m_cursor);
        scene->setInput(m_input);
        scene->setRenderer(m_renderer);
        scene->setTimer(m_timer);
        scene->setWindow(m_window);

        if (1 == m_scenes.size())
        {
            m_currentScene = scene;
        }

        return true;
    }

    return false;
}

NS_END_JKB

#endif // __APPLICATION_H__
