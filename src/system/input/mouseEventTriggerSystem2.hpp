//
// mouseEventTriggerSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 09/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_EVENT_TRIGGER_SYSTEM_2_H__
#define __MOUSE_EVENT_TRIGGER_SYSTEM_2_H__

#include "system/system2.hpp"
#include "core/input/input2.hpp"

namespace Jackbengine {

class MouseEventTriggerSystem2 : public System2
{
    DISALLOW_COPY_AND_MOVE(MouseEventTriggerSystem2)

public:
    explicit MouseEventTriggerSystem2(const Input2& input);
    ~MouseEventTriggerSystem2() override = default;

    void setBubbling(bool active);

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const Input2& m_input;
    bool m_bubbling {false};
};

} // namespace Jackbengine

#endif // __MOUSE_EVENT_TRIGGER_SYSTEM_2_H__
