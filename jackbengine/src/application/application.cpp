//
// application.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
//

#include "core/log/profile.h"
#include "core/log/tracer.h"
#include "core/imgui/imguiLoader.h"
#include "core/sdl/sdlLoader.h"
#include "application.h"

namespace Jackbengine {

Application::Application(ApplicationConfig& config)
{
    TRACE("Application::Application");

    Log::init();
    srand(time(nullptr));

    details::initSDL();

    m_timer = std::make_unique<details::Timer>(config.core_fps);
    m_cursor = std::make_unique<details::Cursor>();
    m_window = std::make_unique<details::Window>(config.general_title, config.render_width, config.render_height, config.render_fullscreen);
    m_textureManager = std::make_unique<details::TextureManager>();
    m_shaderManager = std::make_unique<details::ShaderManager>();
    m_renderer = std::make_unique<details::Renderer>(*m_window, *m_textureManager, *m_shaderManager);
    m_eventManager = std::make_unique<details::EventManager>(BIND_EVENT_CALLBACK(&Application::onEvent));
    m_layerManager = std::make_unique<details::LayerManager>();

    details::initImGui(m_window.get());

    addLayer<DebugLayer>(m_timer.get(), m_window.get());
}

Application::~Application()
{
    TRACE("Application::~Application");

    details::destroyImGui();
    details::destroySDL();
}

bool Application::running() const
{
    return m_running;
}

void Application::update()
{
    TRACE("Application::update");

    const auto delta = m_timer->elapsedSeconds();
    m_timer->start();
    m_renderer->clear();

    m_eventManager->update(delta);
    userUpdate(delta);

    m_renderer->colorTest();
    m_layerManager->update(delta);

    m_renderer->present();
    m_timer->snapshot();
}

void Application::userUpdate(float delta)
{
    TRACE("Application::userUpdate");

    update(delta);
}

void Application::onEvent(Event& e)
{
    EventDispatcher dispatcher(e);
    dispatcher.dispatch<ApplicationCloseEvent>(BIND_EVENT_CALLBACK(&Application::onApplicationCloseEvent));

    m_layerManager->onEvent(e);
}

bool Application::onApplicationCloseEvent(const ApplicationCloseEvent&)
{
    m_running = false;
    return true;
}

}
