//
// helper.system.hpp
// jackbengine
//
// Created by Damien Bendejacq on 08/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_SYSTEM_H__
#define __HELPER_SYSTEM_H__

#include "ecs/ecsApi.hpp"

namespace Jackbengine {

// Render
#define ADD_SYSTEM_TEXT_RENDER()            ADD_SYSTEM(Jackbengine::TextRenderSystem, renderer())
#define ADD_SYSTEM_SPRITE_RENDER()          ADD_SYSTEM(Jackbengine::SpriteRenderSystem, renderer())

// Mouse
#define ADD_SYSTEM_MOUSE_EVENT_TRIGGER()    ADD_SYSTEM(Jackbengine::MouseEventTriggerSystem, input())

// Debug
#define ADD_SYSTEM_FRAMERATE_DEBUG()        ADD_SYSTEM(Jackbengine::FramerateDebugSystem, renderer(), timer())
#define ADD_SYSTEM_TEXT_DEBUG()             ADD_SYSTEM(Jackbengine::TextDebugSystem, renderer())
#define ADD_SYSTEM_SPRITE_DEBUG()           ADD_SYSTEM(Jackbengine::SpriteDebugSystem, renderer())

}

#endif // __HELPER_SYSTEM_H__
