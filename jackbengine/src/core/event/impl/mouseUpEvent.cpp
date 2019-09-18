//
// mouseUpEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "fmt/format.h"
#include "mouseUpEvent.h"

namespace Jackbengine {

std::string MouseUpEvent::toString() const
{
    return fmt::format("MouseUpEvent: x={}, y={}, button={}", x(), y(), (int) m_button);
}

}
