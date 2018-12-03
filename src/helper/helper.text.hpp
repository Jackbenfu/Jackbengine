//
// helper.text.hpp
// jackbengine
//
// Created by Damien Bendejacq on 03/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_TEXT_H__
#define __HELPER_TEXT_H__

#include "ecs/ecsManager.hpp"

namespace Jackbengine {

#define TEXT(text, rect, layout, color, size, font)                                                     \
{                                                                                                       \
    auto entity = ADD_ENTITY();                                                                         \
    ADD_COMPONENT(entity, Jackbengine::ContainerComponent, rect.x, rect.y, rect.w, rect.h);             \
    ADD_COMPONENT(entity, Jackbengine::Text, renderer(), text, layout, color, size, font, font##_size); \
}

#define TEXT_STORE(var, text, rect, layout, color, size, font)                                          \
{                                                                                                       \
    var = ADD_ENTITY();                                                                                 \
    ADD_COMPONENT(var, Jackbengine::ContainerComponent,rect.x, rect.y, rect.w, rect.h);                 \
    ADD_COMPONENT(var, Jackbengine::Text, renderer(), text, layout, color, size, font, font##_size);    \
}

#define TEXT_LAYOUT_LEFT_TOP        Jackbengine::TextLayout::LeftTop
#define TEXT_LAYOUT_LEFT_CENTER     Jackbengine::TextLayout::LeftCenter
#define TEXT_LAYOUT_LEFT_BOTTOM     Jackbengine::TextLayout::LeftBottom
#define TEXT_LAYOUT_CENTER_TOP      Jackbengine::TextLayout::CenterTop
#define TEXT_LAYOUT_CENTER_CENTER   Jackbengine::TextLayout::CenterCenter
#define TEXT_LAYOUT_CENTER_BOTTOM   Jackbengine::TextLayout::CenterBottom
#define TEXT_LAYOUT_RIGHT_TOP       Jackbengine::TextLayout::RightTop
#define TEXT_LAYOUT_RIGHT_CENTER    Jackbengine::TextLayout::RightCenter
#define TEXT_LAYOUT_RIGHT_BOTTOM    Jackbengine::TextLayout::RightBottom

}

#endif // __HELPER_TEXT_H__
