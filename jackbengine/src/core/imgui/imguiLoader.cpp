//
// imguiLoader.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

#include "imguiLoader.h"

namespace Jackbengine::details {

void initImGui(const Window *window)
{
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.DisplaySize = ImVec2 {(float) window->width(), (float) window->height()};
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window->nativeWindow(), window->nativeGLContext());
    ImGui_ImplOpenGL3_Init("#version 330");
}

void destroyImGui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

}
