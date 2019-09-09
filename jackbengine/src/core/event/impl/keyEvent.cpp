//
// keyEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "keyEvent.h"
#include "spdlog/fmt/fmt.h"

namespace Jackbengine::details {

std::string KeyEvent::keys() const
{
    return fmt::format("physicalKey={}, virtualKey={}", (int) physicalKey(), (int) virtualKey());
}

}
