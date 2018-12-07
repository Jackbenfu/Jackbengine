//
// helper.mouse.hpp
// jackbengine
//
// Created by Damien Bendejacq on 05/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_MOUSE_H__
#define __HELPER_MOUSE_H__

namespace Jackbengine {

#define MOUSE_LEFT_CLICKABLE(entity, onClick)                                           \
{                                                                                       \
    if (!HAS_COMPONENT(entity, Jackbengine::Container))                                 \
    {                                                                                   \
        auto sprite = GET_COMPONENT(entity, Jackbengine::Sprite);                       \
        auto transform = GET_COMPONENT(entity, Jackbengine::Transform);                 \
        ADD_COMPONENT(                                                                  \
            entity, Jackbengine::Container,                                             \
            transform->positionX(), transform->positionY(),                             \
            sprite->texture().width(), sprite->texture().height()                       \
        );                                                                              \
    }                                                                                   \
    ADD_COMPONENT_DEFAULT(entity, Jackbengine::MouseListener);                          \
    auto mouseListenerComponent = GET_COMPONENT(entity, Jackbengine::MouseListener);    \
    mouseListenerComponent->onLeftClick(std::function<void()> {onClick});               \
}

}

#endif // __HELPER_MOUSE_H__
