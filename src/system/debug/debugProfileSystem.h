//
// debugProfileSystem.h
// jackbengine
//
// Created by Damien Bendejacq on 23/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_PROFILE_SYSTEM_H__
#define __DEBUG_PROFILE_SYSTEM_H__

#include "system/system.h"
#include "core/render/renderer.h"
#include "core/time/timer.h"
#include "component/view/textComponent.h"

NS_BEGIN_JKB

#define FPS_BUF_SIZE 16

class DebugProfileSystem :
    public System,
    public TypedObject<DebugProfileSystem>
{
public:
    DebugProfileSystem();
    ~DebugProfileSystem();

    void update(float delta) override;

    void setRenderer(Renderer *renderer);
    void setTimer(Timer *timer);
    void setForeground(Color color);

    void showFps(bool show);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
    Timer *m_timer = nullptr;

    // Time elapsed per frame and FPS
    char m_fpsBuf[FPS_BUF_SIZE];
    TextComponent *m_fps = nullptr;
    bool m_showFps = true;
};

NS_END_JKB

#endif // __DEBUG_PROFILE_SYSTEM_H__
