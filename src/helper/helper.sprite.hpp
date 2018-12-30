//
// helper.sprite.hpp
// jackbengine
//
// Created by Damien Bendejacq on 05/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_SPRITE_H__
#define __HELPER_SPRITE_H__

#include "ecs/ecsManager.hpp"

namespace Jackbengine {

// TODO gérer le scale
// TODO gérer la position du pivot (range 0..1, pas en pixels)
// TODO gérer les autres events mouse
// TODO gérer le clic sur un élément non AABB
// TODO ajouter les systèmes manquants aux helpers

#define SPRITE_DATA(data, position, zIndex, scale, angle)                                           \
{                                                                                                   \
    auto entity = ADD_ENTITY();                                                                     \
    ADD_COMPONENT(entity, Jackbengine::Sprite, renderer(), data, data##_size);                      \
    ADD_COMPONENT(entity, Jackbengine::Transform, position.x, position.y, scale.x, scale.y, angle); \
    ADD_COMPONENT(entity, Jackbengine::ZIndex, zIndex);                                             \
}

#define SPRITE_DATA_ENTITY(entity, data, position, zIndex, scale, angle)                            \
{                                                                                                   \
    entity = ADD_ENTITY();                                                                          \
    ADD_COMPONENT(entity, Jackbengine::Sprite, renderer(), data, data##_size);                      \
    ADD_COMPONENT(entity, Jackbengine::Transform, position.x, position.y, scale.x, scale.y, angle); \
    ADD_COMPONENT(entity, Jackbengine::ZIndex, zIndex);                                             \
}

}

#endif // __HELPER_SPRITE_H__
