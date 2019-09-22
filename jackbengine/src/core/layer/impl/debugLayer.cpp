//
// debugLayer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

#include "core/event/event.h"
#include "core/log/log.h"
#include "debugLayer.h"

namespace Jackbengine {

DebugLayer::DebugLayer(const details::Timer *timer, const details::Window *window)
    : m_timer {timer},
      m_window {window}
{
}

void DebugLayer::update(float)
{
    if (!m_timer->fps().has_value())
    {
        return;
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(m_window->nativeWindow());
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always, ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_window->width(), 32), ImGuiCond_Always);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin(
        "DebugLayerTimer",
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

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DebugLayer::onEvent(Event &e)
{
    EventDispatcher dispatcher(e);

    dispatcher.dispatch<KeyDownEvent>(BIND_EVENT_CALLBACK(&DebugLayer::onKeyDownEvent));
    dispatcher.dispatch<KeyUpEvent>(BIND_EVENT_CALLBACK(&DebugLayer::onKeyUpEvent));
    dispatcher.dispatch<MouseMotionEvent>(BIND_EVENT_CALLBACK(&DebugLayer::onMouseMotionEvent));
    dispatcher.dispatch<MouseDownEvent>(BIND_EVENT_CALLBACK(&DebugLayer::onMouseDownEvent));
    dispatcher.dispatch<MouseUpEvent>(BIND_EVENT_CALLBACK(&DebugLayer::onMouseUpEvent));
}

bool DebugLayer::onKeyDownEvent(const KeyDownEvent &e)
{
    LOG_INFO(e.toString());
    return false;
}

bool DebugLayer::onKeyUpEvent(const KeyUpEvent &e)
{
    LOG_INFO(e.toString());
    return false;
}

bool DebugLayer::onMouseMotionEvent(const MouseMotionEvent &e)
{
    LOG_INFO(e.toString());
    return false;
}

bool DebugLayer::onMouseDownEvent(const MouseDownEvent &e)
{
    LOG_INFO(e.toString());
    return false;
}

bool DebugLayer::onMouseUpEvent(const MouseUpEvent &e)
{
    LOG_INFO(e.toString());
    return false;
}

}
