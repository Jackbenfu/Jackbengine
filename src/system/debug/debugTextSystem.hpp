//
// debugTextSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 24/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __DEBUG_TEXT_SYSTEM_H__
#define __DEBUG_TEXT_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer.hpp"

namespace Jackbengine {

class DebugTextSystem : public System
{
public:
    DebugTextSystem();
    ~DebugTextSystem() override;

    void update(float delta) override;

    void setRenderer(Renderer *renderer);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    Renderer *m_renderer = nullptr;
};

} // namespace Jackbengine

#endif // __DEBUG_TEXT_SYSTEM_H__
