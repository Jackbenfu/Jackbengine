//
// mouseMotionEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "fmt/format.h"
#include "mouseMotionEvent.h"

namespace Jackbengine {

std::string MouseMotionEvent::toString() const
{
    return fmt::format("MouseMotionEvent: x={}, y={}", x(), y());
}

}
