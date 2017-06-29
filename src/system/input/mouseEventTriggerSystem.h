//
// mouseEventTriggerSystem.h
// jackbengine
//
// Created by Damien Bendejacq on 28/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __MOUSE_EVENT_TRIGGER_SYSTEM_H__
#define __MOUSE_EVENT_TRIGGER_SYSTEM_H__

#include "system/system.h"
#include "core/input/input.h"

NS_BEGIN_JKB

class MouseEventTriggerSystem :
    public System,
    public TypedObject<MouseEventTriggerSystem>
{
public:
    MouseEventTriggerSystem();
    ~MouseEventTriggerSystem();

    void update(float delta) override;

    void setBubblingActive(bool active);
    void setInput(Input *input);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Input *m_input = nullptr;
    bool m_bubblingActive = false;
};

NS_END_JKB

#endif // __MOUSE_EVENT_TRIGGER_SYSTEM_H__
