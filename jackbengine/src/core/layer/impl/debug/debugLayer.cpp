//
// debugLayer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
//

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

#include "core/event/event.h"
#include "core/profile/profiler.h"
#include "debugLayer.h"

namespace Jackbengine {

DebugLayer::DebugLayer(const details::Timer* timer, const details::Window* window, bool demo)
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

    PROFILE("DebugLayer::update");

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(m_window->nativeWindow());
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2((float) m_window->width(), (float) m_window->height()), ImGuiCond_Always);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);

    printTiming();

    if (m_demo)
    {
        ImGui::SetNextWindowPos(ImVec2(0, 20), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2 {(float) m_window->width(), (float) m_window->height()}, ImGuiCond_Always);
        ImGui::ShowDemoWindow(&m_demo);
    }

#ifdef __RELEASE_PROFILE__
    if (!m_demo)
    {
        ImGui::SetNextWindowPos(ImVec2(0, 20), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2 {(float) m_window->width(), (float) m_window->height() - 20}, ImGuiCond_Always);
        ImGui::Begin(
            "Profilers",
            nullptr,
            (unsigned) ImGuiWindowFlags_NoTitleBar
            | ImGuiWindowFlags_NoResize
            | ImGuiWindowFlags_NoMove
        );

        printSampleProfiler();

        ImGui::End();
    }
#endif

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DebugLayer::onEvent(Event&)
{
    // Nothing
}

void DebugLayer::printTiming()
{
    ImGui::Begin(
        "Timing",
        nullptr,
        (unsigned) ImGuiWindowFlags_NoTitleBar
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

    ImGui::End();
}

void DebugLayer::printSampleProfiler()
{
    if (!ImGui::CollapsingHeader("Sample profiler"))
    {
        return;
    }

    ImGui::Columns(4);

    ImGui::SetColumnWidth(0, (float) m_window->width() - 75 * 3);
    ImGui::SetColumnWidth(1, 75);
    ImGui::SetColumnWidth(2, 75);
    ImGui::SetColumnWidth(3, 75);

    ImGui::Text("Sample");
    ImGui::NextColumn();
    ImGui::Text("Avg (ms)");
    ImGui::NextColumn();
    ImGui::Text("Min (ms)");
    ImGui::NextColumn();
    ImGui::Text("Max (ms)");
    ImGui::NextColumn();

    ImGui::Separator();

    std::sort(
        details::Profiler::instance().begin(),
        details::Profiler::instance().end(),
        [](details::ProfileSample& ps1, details::ProfileSample& ps2)
        {
            return ps1.average() > ps2.average();
        }
    );

    std::for_each(
        details::Profiler::instance().begin(),
        details::Profiler::instance().end(),
        [](const details::ProfileSample& ps)
        {
            ImGui::Text("%s", ps.name());
            ImGui::NextColumn();
            ImGui::Text("%.2f", ps.average());
            ImGui::NextColumn();
            ImGui::Text("%.2f", ps.min());
            ImGui::NextColumn();
            ImGui::Text("%.2f", ps.max());
            ImGui::NextColumn();
        }
    );
}

}
