//
//  Jackbengine.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 22/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __JACKBENGINE_H__
#define __JACKBENGINE_H__

// Core
#include "core/audio/sound.h"
#include "core/input/input.h"
#include "core/math/rect.h"
#include "core/math/vector2d.h"
#include "core/network/webSocket.h"
#include "core/render/color.h"
#include "core/render/cursor.h"
#include "core/render/font.h"
#include "core/render/renderer.h"
#include "core/render/texture.h"
#include "core/render/window.h"
#include "core/resource/importResource.h"
#include "core/time/timer.h"
#include "core/tmx/tmxMap.h"

// Entity
#include "entity/entity.h"
#include "entity/entityManager.h"

// Component
#include "component/component.h"
#include "component/audio/audioSourceComponent.h"
#include "component/body/shape/boxShapeComponent.h"
#include "component/body/transformComponent.h"
#include "component/body/velocityComponent.h"
#include "component/generic/genericComponent.h"
#include "component/input/mouseListenerComponent.h"
#include "component/layout/containerComponent.h"
#include "component/misc/tagComponent.h"
#include "component/view/colorComponent.h"
#include "component/view/spriteComponent.h"
#include "component/view/textComponent.h"

// System
#include "system/system.h"
#include "system/animation/motionSystem.h"
#include "system/debug/debugProfileSystem.h"
#include "system/debug/debugSpriteSystem.h"
#include "system/debug/debugTextSystem.h"
#include "system/input/mouseEventTriggerSystem.h"
#include "system/physic/aabbCollisionSystem.h"
#include "system/render/spriteRenderSystem.h"
#include "system/render/textRenderSystem.h"

// Application
#include "application/application.h"

#endif // __JACKBENGINE_H__
