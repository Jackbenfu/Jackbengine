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

#include "core/log/tracer.h"
#include "core/event/event.h"
#include "debugLayer.h"

namespace Jackbengine {

DebugLayer::DebugLayer(const details::Timer *timer, const details::Window *window, bool demo)
    : m_timer {timer},
      m_window {window},
      m_demo {demo}
{
}

void DebugLayer::update(float)
{
    if (!m_timer->fps().has_value())
    {
        return;
    }

    TRACE("DebugLayer::update");

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(m_window->nativeWindow());
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(m_window->width(), 20), ImGuiCond_Always);
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

#if defined(__DEBUG__)
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "[DEBUG]");
    ImGui::SameLine();
#elif defined(__RELEASE_PROFILE__)
    ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "[RELEASE_PROFILE]");
    ImGui::SameLine();
#elif defined(__RELEASE__)
    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "[RELEASE]");
    ImGui::SameLine();
#endif

    ImGui::Text(
        "%.1f FPS (spent=%.2fms, waiting=%.2fms, total=%.2fms) frame #%u",
        m_timer->fps().value(),
        m_timer->averageSpentMilliseconds(),
        m_timer->averageWaitingMilliseconds(),
        m_timer->averageElapsedMilliseconds(),
        m_timer->totalFrames()
    );
    ImGui::PopStyleVar();
    ImGui::End();

    if (m_demo)
    {
        ImGui::SetNextWindowPos(ImVec2(0, 20), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2 {(float) m_window->width() * 2 / 3, (float) m_window->height() * 2 / 3}, ImGuiCond_Always);
        ImGui::ShowDemoWindow(&m_demo);
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DebugLayer::onEvent(Event &)
{
}

}
