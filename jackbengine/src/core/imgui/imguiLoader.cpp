//
// imguiLoader.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
//

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

#include "imguiLoader.h"

namespace Jackbengine::details {

void initImGui(const Window* window)
{
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.DisplaySize = ImVec2 {(float) window->width(), (float) window->height()};
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // NOLINT(hicpp-signed-bitwise)
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // NOLINT(hicpp-signed-bitwise)

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window->nativeWindow(), window->nativeGLContext());
#ifdef EMSCRIPTEN
    ImGui_ImplOpenGL3_Init("#version 100");
#else
    ImGui_ImplOpenGL3_Init("#version 330 core");
#endif
}

void destroyImGui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

}
