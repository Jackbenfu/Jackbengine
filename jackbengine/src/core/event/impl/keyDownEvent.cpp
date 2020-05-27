//
// keyDownEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
//

#include "fmt/format.h"
#include "keyDownEvent.h"

namespace Jackbengine {

std::string KeyDownEvent::toString() const
{
    return fmt::format("KeyDownEvent: {}, repeat={}", keys(), m_repeat);
}

}
