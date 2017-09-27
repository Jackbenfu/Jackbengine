//
// jackbengine.hpp
// jackbengine
//
// Created by Damien Bendejacq on 22/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __JACKBENGINE_H__
#define __JACKBENGINE_H__

// Core
#include "core/audio/sound.hpp"
#include "core/debug/profile.hpp"
#include "core/input/input.hpp"
#include "core/math/rect.hpp"
#include "core/math/vector2d.hpp"
#include "core/network/webSocket.hpp"
#include "core/render/color32.hpp"
#include "core/render/cursor.hpp"
#include "core/render/font.hpp"
#include "core/render/renderer.hpp"
#include "core/render/texture.hpp"
#include "core/render/window.hpp"
#include "core/resource/importResource.hpp"
#include "core/time/timer.hpp"
#include "core/tmx/tmxMap.hpp"

// Entity
#include "entity/entity.hpp"

// Component
#include "component/component.hpp"
#include "component/audio/audioSourceComponent.hpp"
#include "component/body/shape/boxShapeComponent.hpp"
#include "component/body/transformComponent.hpp"
#include "component/body/velocityComponent.hpp"
#include "component/generic/genericComponent.hpp"
#include "component/input/mouseListenerComponent.hpp"
#include "component/layout/containerComponent.hpp"
#include "component/layout/zOrderComponent.hpp"
#include "component/misc/nameComponent.hpp"
#include "component/misc/tagComponent.hpp"
#include "component/view/colorComponent.hpp"
#include "component/view/spriteComponent.hpp"
#include "component/view/textComponent.hpp"

// System
#include "system/system.hpp"
#include "system/animation/motionSystem.hpp"
#include "system/debug/debugProfileSystem.hpp"
#include "system/debug/debugSpriteSystem.hpp"
#include "system/debug/debugTextSystem.hpp"
#include "system/input/mouseEventTriggerSystem.hpp"
#include "system/physic/aabbCollisionSystem.hpp"
#include "system/render/spriteRenderSystem.hpp"
#include "system/render/textRenderSystem.hpp"

// Application
#include "application/application.hpp"

// Scene
#include "scene/loader/tmx/tmxSceneLoader.hpp"

//////
// NEW
//////

// Core
#include "core/audio/sound2.hpp"
#include "core/input/input2.hpp"
#include "core/render/cursor/cursor2.hpp"
#include "core/render/font/font2.hpp"
#include "core/render/renderer/renderer2.hpp"
#include "core/render/texture/texture2.hpp"
#include "core/render/window/window2.hpp"
#include "core/state/stateMachine.hpp"
#include "core/time/timer2.hpp"

// Component
#include "component/component2.hpp"
#include "component/audio/audioSourceComponent2.hpp"
#include "component/body/shape/boxShapeComponent2.hpp"
#include "component/body/transformComponent2.hpp"
#include "component/body/velocityComponent2.hpp"
#include "component/generic/stringComponent.hpp"
#include "component/generic/numericalComponent.hpp"
#include "component/input/mouseListenerComponent2.hpp"
#include "component/layout/containerComponent2.hpp"
#include "component/layout/zOrderComponent2.hpp"
#include "component/misc/nameComponent2.hpp"
#include "component/misc/tagComponent2.hpp"
#include "component/view/colorComponent2.hpp"
#include "component/view/spriteComponent2.hpp"
#include "component/view/textComponent2.hpp"

// System
#include "system/system2.hpp"
#include "system/animation/motionSystem2.hpp"
#include "system/debug/debugProfileSystem2.hpp"
#include "system/debug/debugSpriteSystem2.hpp"
#include "system/debug/debugTextSystem2.hpp"
#include "system/input/mouseEventTriggerSystem2.hpp"
#include "system/render/spriteRenderSystem2.hpp"
#include "system/render/textRenderSystem2.hpp"

// Application
#include "application/application2.hpp"

// Scene
#include "scene/scene2.hpp"

#endif // __JACKBENGINE_H__
