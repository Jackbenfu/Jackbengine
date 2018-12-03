//
// systemOrder.hpp
// jackbengine
//
// Created by Damien Bendejacq on 18/10/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_ORDER_H__
#define __SYSTEM_ORDER_H__

namespace Jackbengine {

enum class SystemOrder
{
    Motion = 10000,
    MouseEventTrigger = 20000,
    AABBCollision = 30000,
    SpriteRender = 40000,
    SpriteDebug = 40001,
    TextRender = 50000,
    TextDebug = 50001,
    FramerateDebug = 60000,
};

}

#endif // __SYSTEM_ORDER_H__
