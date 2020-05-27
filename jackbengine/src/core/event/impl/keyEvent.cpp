//
// keyEvent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2019.
//

#include "fmt/format.h"
#include "keyEvent.h"

namespace Jackbengine {

std::string KeyEvent::keys() const
{
    return fmt::format("physicalKey={}, virtualKey={}", (int) physicalKey(), (int) virtualKey());
}

}
