//
// application.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
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
#include "core/render/renderer/renderer.h"

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
    [[maybe_unused]] void removeLayer();

#ifdef EMSCRIPTEN
    public:
        void update();
#else
private:
    void update();
#endif

private:
    [[nodiscard]] bool running() const;
    void userUpdate(float delta);

    void onEvent(Event &e);
    bool onApplicationCloseEvent(const ApplicationCloseEvent &e);

    std::unique_ptr<details::Timer> m_timer;
    [[maybe_unused]] std::unique_ptr<details::Cursor> m_cursor;
    std::unique_ptr<details::Window> m_window;
    std::unique_ptr<details::TextureManager> m_textureManager;
    std::unique_ptr<details::ShaderManager> m_shaderManager;
    std::unique_ptr<details::Renderer> m_renderer;
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
[[maybe_unused]] void Application::removeLayer()
{
    m_layerManager->remove<TLayer>();
}

}

#endif // __APPLICATION_H__
