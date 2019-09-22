//
// application.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "applicationConfig.h"

#include "core/event/eventManager.h"
#include "core/event/impl/eventImpl.h"

#include "core/layer/layerManager.h"
#include "core/layer/impl/debugLayer.h"

#include "core/time/timer.h"
#include "core/render/cursor/cursor.h"
#include "core/render/window/window.h"
#include "core/render/renderer/glRenderer.h"

namespace Jackbengine {

namespace details {

class ApplicationWrapper;

}

class Application
{
    friend class details::ApplicationWrapper;

public:
    Application() = delete;
    explicit Application(ApplicationConfig &config);
    virtual ~Application();

protected:
    virtual void update(float delta) = 0;

    template<typename TLayer, typename ...Args>
    void addLayer(Args &&...args);

    template<typename TLayer>
    void removeLayer();

private:
    [[nodiscard]] bool running() const;
    void update();
    void userUpdate(float delta);

    void onEvent(Event &e);
    bool onApplicationCloseEvent(const ApplicationCloseEvent &e);

    std::unique_ptr<details::Timer> m_timer;
    std::unique_ptr<details::Cursor> m_cursor;
    std::unique_ptr<details::Window> m_window;
    std::unique_ptr<details::GlRenderer> m_renderer;
    std::unique_ptr<details::EventManager> m_eventManager;
    std::unique_ptr<details::LayerManager> m_layerManager;

    bool m_running {true};
};

template<typename TLayer, typename ...Args>
void Application::addLayer(Args &&...args)
{
    m_layerManager->add<TLayer>(args...);
}

template<typename TLayer>
void Application::removeLayer()
{
    m_layerManager->remove<TLayer>();
}

}

#endif // __APPLICATION_H__
