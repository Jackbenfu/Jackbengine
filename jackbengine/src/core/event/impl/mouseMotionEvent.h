//
// mouseMotionEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 22/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_MOTION_EVENT_H__
#define __MOUSE_MOTION_EVENT_H__

#include "mouseEvent.h"

namespace Jackbengine {

class MouseMotionEvent : public MouseEvent
{
public:
    EVENT_CLASS_TYPE(EventType::MouseMotion)

    MouseMotionEvent(int x, int y)
        : MouseEvent {x, y}
    {}

    [[nodiscard]] std::string toString() const override;
};

}

#endif // __MOUSE_MOTION_EVENT_H__
