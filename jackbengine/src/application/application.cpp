//
// application.cpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

#include "core/log/profile.h"
#include "core/sdl/sdlinc.h"
#include "application.h"

namespace Jackbengine {

Application::Application(ApplicationConfig &config)
{
    Log::init();
    srand(time(nullptr));

    {
        NO_PROFILE("Application::Application")

#ifdef EMSCRIPTEN
        if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_TIMER | SDL_INIT_HAPTIC)) < 0)
#else
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
#endif
        {
            throw std::runtime_error(SDL_GetError());
        }

        if (TTF_Init() < 0)
        {
            throw std::runtime_error(TTF_GetError());
        }

        if (0 == Mix_Init((unsigned) MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
        {
            throw std::runtime_error(Mix_GetError());
        }

        if (-1 == Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
        {
            throw std::runtime_error(Mix_GetError());
        }

        m_timer = std::make_unique<details::Timer>(config.core_fps);
        m_cursor = std::make_unique<details::Cursor>();
        m_window = std::make_unique<details::Window>(
            config.general_title,
            config.render_width,
            config.render_height,
            config.render_fullscreen
        );
        m_renderer = std::make_unique<details::GlRenderer>(*m_window);
        m_eventManager = std::make_unique<details::EventManager>(BIND_EVENT_CALLBACK(onEvent));

        m_renderer->initTextureTest();

        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.IniFilename = nullptr;
        io.DisplaySize = ImVec2 {(float) m_window->width(), (float) m_window->height()};
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(m_window->nativeWindow(), m_window->nativeGLContext());
        ImGui_ImplOpenGL3_Init("#version 330");
    }
}

Application::~Application()
{
    {
        NO_PROFILE("Application::~Application")

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

        Mix_Quit();
        TTF_Quit();
        SDL_Quit();
    }
}

bool Application::running() const
{
    return m_running;
}

void Application::frame()
{
    {
        NO_PROFILE("Application::frame")

        m_timer->start();
        const auto delta = m_timer->elapsedSeconds();

        m_renderer->clear();
        m_eventManager->update();

        userFrame(delta);

        m_renderer->textureTest();

        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL2_NewFrame(m_window->nativeWindow());
            ImGui::NewFrame();

            if (m_timer->fps().has_value())
            {
                ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always, ImVec2(0, 0));
                ImGui::SetNextWindowSize(ImVec2(m_window->width(), 32), ImGuiCond_Always);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
                ImGui::Begin(
                    "Timer",
                    nullptr,
                    ImGuiWindowFlags_NoTitleBar
                    | ImGuiWindowFlags_NoResize
                    | ImGuiWindowFlags_NoMove
                    | ImGuiWindowFlags_NoScrollbar
                    | ImGuiWindowFlags_NoBackground
                    | ImGuiWindowFlags_NoInputs
                );
                ImGui::Text(
                    "%.1f FPS (spent=%.2fms, waiting=%.2fms, total=%.2fms) frame #%u",
                    m_timer->fps().value(),
                    m_timer->spentMilliseconds(),
                    m_timer->waitingMilliseconds(),
                    m_timer->elapsedMilliseconds(),
                    m_timer->totalFrames()
                );
                ImGui::PopStyleVar();
                ImGui::End();
            }
        }

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    m_renderer->present();

    m_timer->snapshot();
}

void Application::userFrame(float delta)
{
    {
        NO_PROFILE("Application::userFrame")
        frame(delta);
    }
}

void Application::onEvent(details::Event &e)
{
    details::EventDispatcher dispatcher(e);

    dispatcher.dispatch<ApplicationCloseEvent>(BIND_EVENT_CALLBACK(onApplicationCloseEvent));
    dispatcher.dispatch<KeyDownEvent>(BIND_EVENT_CALLBACK(onKeyDownEvent));
    dispatcher.dispatch<KeyUpEvent>(BIND_EVENT_CALLBACK(onKeyUpEvent));
    dispatcher.dispatch<MouseMotionEvent>(BIND_EVENT_CALLBACK(onMouseMotionEvent));
    dispatcher.dispatch<MouseDownEvent>(BIND_EVENT_CALLBACK(onMouseDownEvent));
    dispatcher.dispatch<MouseUpEvent>(BIND_EVENT_CALLBACK(onMouseUpEvent));
}

bool Application::onApplicationCloseEvent(const ApplicationCloseEvent &)
{
    m_running = false;
    return true;
}

bool Application::onKeyDownEvent(const KeyDownEvent &)
{
    return true;
}

bool Application::onKeyUpEvent(const KeyUpEvent &)
{
    return true;
}

bool Application::onMouseMotionEvent(const MouseMotionEvent &)
{
    return true;
}

bool Application::onMouseDownEvent(const MouseDownEvent &)
{
    return true;
}

bool Application::onMouseUpEvent(const MouseUpEvent &)
{
    return true;
}

}
