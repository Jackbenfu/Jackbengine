//
// mouseEventTriggerSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 28/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_EVENT_TRIGGER_SYSTEM_H__
#define __MOUSE_EVENT_TRIGGER_SYSTEM_H__

#include "system/system.hpp"
#include "core/input/input.hpp"

namespace Jackbengine {

class MouseEventTriggerSystem : public System
{
public:
    MouseEventTriggerSystem();
    ~MouseEventTriggerSystem() override;

    void update(float delta) override;

    void setBubblingActive(bool active);
    void setInput(Input *input);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Input *m_input = nullptr;
    bool m_bubblingActive = false;
};

} // namespace Jackbengine

#endif // __MOUSE_EVENT_TRIGGER_SYSTEM_H__
