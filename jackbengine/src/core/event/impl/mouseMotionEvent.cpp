//
// mouseMotionEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "mouseMotionEvent.h"
#include "spdlog/fmt/fmt.h"

namespace Jackbengine {

std::string MouseMotionEvent::toString() const
{
    return fmt::format("MouseMotionEvent: x={}, y={}", x(), y());
}

}
