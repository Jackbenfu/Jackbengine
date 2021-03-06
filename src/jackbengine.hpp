//
// jackbengine.hpp
// jackbengine
//
// Created by Damien Bendejacq on 22/04/2014.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __JACKBENGINE_H__
#define __JACKBENGINE_H__

// Core
#include "core/audio/sound.hpp"
#include "core/log/profile.hpp"
#include "core/input/input.hpp"
#include "core/log/log.hpp"
#include "core/math/rect.hpp"
#include "core/math/vector2d.hpp"
#include "core/render/color.hpp"
#include "core/render/cursor/cursor.hpp"
#include "core/render/font/font.hpp"
#include "core/render/renderer/renderer.hpp"
#include "core/render/texture/texture.hpp"
#include "core/render/window/window.hpp"
#include "core/resource/importResource.hpp"
#include "core/state/stateMachine.hpp"
#include "core/time/timer.hpp"

// Component
#include "component/component.hpp"
#include "component/audio/audioSourceComponent.hpp"
#include "component/body/shape/boxShapeComponent.hpp"
#include "component/body/transformComponent.hpp"
#include "component/body/velocityComponent.hpp"
#include "component/generic/stringComponent.hpp"
#include "component/generic/numericalComponent.hpp"
#include "component/input/mouseListenerComponent.hpp"
#include "component/layout/containerComponent.hpp"
#include "component/layout/zIndexComponent.hpp"
#include "component/misc/nameComponent.hpp"
#include "component/misc/tagComponent.hpp"
#include "component/view/colorComponent.hpp"
#include "component/view/spriteComponent.hpp"
#include "component/view/textComponent.hpp"

// System
#include "system/system.hpp"
#include "system/animation/motionSystem.hpp"
#include "system/debug/framerateDebugSystem.hpp"
#include "system/debug/spriteDebugSystem.hpp"
#include "system/debug/textDebugSystem.hpp"
#include "system/input/mouseEventTriggerSystem.hpp"
#include "system/physic/aabbCollisionSystem.hpp"
#include "system/render/spriteRenderSystem.hpp"
#include "system/render/textRenderSystem.hpp"

// ECS
#include "ecs/ecsApi.hpp"

// Helper
#include "helper/helper.color.hpp"
#include "helper/helper.mouse.hpp"
#include "helper/helper.math.hpp"
#include "helper/helper.sprite.hpp"
#include "helper/helper.system.hpp"
#include "helper/helper.text.hpp"

// Application
#include "application/application.hpp"

#endif // __JACKBENGINE_H__
