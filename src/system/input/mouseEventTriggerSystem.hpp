//
// mouseEventTriggerSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_EVENT_TRIGGER_SYSTEM_H__
#define __MOUSE_EVENT_TRIGGER_SYSTEM_H__

#include "system/system.hpp"
#include "core/input/input.hpp"

namespace Jackbengine {

class MouseEventTriggerSystem final : public System
{
public:
    MouseEventTriggerSystem() = delete;
    explicit MouseEventTriggerSystem(const Input& input);
    ~MouseEventTriggerSystem() override = default;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const Input& m_input;
};

}

#endif // __MOUSE_EVENT_TRIGGER_SYSTEM_H__
