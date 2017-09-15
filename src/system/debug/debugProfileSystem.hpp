//
// debugProfileSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 23/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_PROFILE_SYSTEM_H__
#define __DEBUG_PROFILE_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer.hpp"
#include "core/time/timer.hpp"
#include "component/view/textComponent.hpp"

namespace Jackbengine {

#define FPS_BUF_SIZE 16

class DebugProfileSystem final : public System
{
public:
    DebugProfileSystem();
    ~DebugProfileSystem() override;

    void update(float delta) override;

    void setRenderer(Renderer *renderer);
    void setTimer(Timer *timer);
    void setForeground(Color32 color);

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

} // namespace Jackbengine

#endif // __DEBUG_PROFILE_SYSTEM_H__
