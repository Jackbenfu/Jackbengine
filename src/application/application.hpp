//
// application.hpp
// jackbengine
//
// Created by Damien Bendejacq on 10/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <map>
#include "applicationConfig.hpp"
#include "scene/scene.hpp"

namespace Jackbengine {

class Application
{
public:
    bool init();
    bool running() const;
    void loop();

protected:
    Application();
    virtual ~Application();

    virtual bool configure(ApplicationConfig &config) = 0;

    template<typename TScene> void addScene();

private:
    void setSceneFeatures(Scene &scene);
    Scene *getScene(const char *name);

    ApplicationConfig m_config;

    Scene *m_currentScene = nullptr;
    std::map<size_t, Scene *> m_scenes;

    Cursor *m_cursor = nullptr;
    Input *m_input = nullptr;
    Renderer *m_renderer = nullptr;
    Timer *m_timer = nullptr;
    Window *m_window = nullptr;
};

#include "application.tpp"

} // namespace Jackbengine

#endif // __APPLICATION_H__
