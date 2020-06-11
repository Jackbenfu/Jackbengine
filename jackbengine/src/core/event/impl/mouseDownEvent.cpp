//
// mouseDownEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
//

#include "fmt/format.h"
#include "mouseDownEvent.h"

namespace Jackbengine {

std::string MouseDownEvent::toString() const
{
    return fmt::format("MouseDownEvent: x={}, y={}, button={}, repeat={}", x(), y(), (int) m_button, m_repeat);
}

}