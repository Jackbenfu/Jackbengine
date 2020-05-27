//
// keyUpEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
//

#include "fmt/format.h"
#include "keyUpEvent.h"

namespace Jackbengine {

std::string KeyUpEvent::toString() const
{
    return fmt::format("KeyUpEvent: {}", keys());
}

}
