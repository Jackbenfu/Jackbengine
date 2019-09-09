//
// keyUpEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "keyUpEvent.h"
#include "spdlog/fmt/fmt.h"

namespace Jackbengine {

std::string KeyUpEvent::toString() const
{
    return fmt::format("KeyUpEvent: {}", keys());
}

}
