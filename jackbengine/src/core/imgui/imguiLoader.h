//
// imguiLoader.h
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
//

#ifndef __IMGUI_LOADER_H__
#define __IMGUI_LOADER_H__

#include "core/render/window/window.h"

namespace Jackbengine::details {

void initImGui(const Window *window);
void destroyImGui();

}

#endif // __IMGUI_LOADER_H__
