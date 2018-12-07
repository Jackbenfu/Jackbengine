//
// ecsApi.hpp
// jackbengine
//
// Created by Damien Bendejacq on 01/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __ECS_API_H__
#define __ECS_API_H__

#include "ecsManager.hpp"

namespace Jackbengine {

/*
 * Entity
 */
#define ENTITY(entity)                          Jackbengine::Entity entity
#define ADD_ENTITY()                            Jackbengine::EcsManager::getManager().addEntity()
#define REMOVE_ENTITY(entity)                   Jackbengine::EcsManager::getManager().removeEntity(entity)
#define ENABLE_ENTITY(entity, enable)           Jackbengine::EcsManager::getManager().enableEntity(entity, enable)

/*
 * Component
 */
#define ADD_COMPONENT_DEFAULT(entity, type)     Jackbengine::EcsManager::getManager().addComponent<type>(entity)
#define ADD_COMPONENT(entity, type, ...)        Jackbengine::EcsManager::getManager().addComponent<type>(entity, __VA_ARGS__)
#define GET_COMPONENT(entity, type)             Jackbengine::EcsManager::getManager().getComponent<type>(entity)
#define HAS_COMPONENT(entity, type)             Jackbengine::EcsManager::getManager().hasComponent<type>(entity)
#define ENABLE_COMPONENT(entity, type, enable)  Jackbengine::EcsManager::getManager().enableComponent<type>(entity, enable)

/*
 * System
 */
#define ADD_SYSTEM(type, ...)                   Jackbengine::EcsManager::getManager().addSystem<type>(__VA_ARGS__)
#define GET_SYSTEM(type)                        Jackbengine::EcsManager::getManager().getSystem<type>()
#define ENABLE_SYSTEM(type, enable)             Jackbengine::EcsManager::getManager().enableSystem<type>(enable)

}

#endif // __ECS_API_H__
