//
// keyDownEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "keyDownEvent.h"
#include "spdlog/fmt/fmt.h"

namespace Jackbengine {

std::string KeyDownEvent::toString() const
{
    return fmt::format("KeyDownEvent: {}, repeat={}", keys(), m_repeat);

}

}
