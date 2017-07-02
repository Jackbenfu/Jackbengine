//
// motionSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/05/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __MOTION_SYSTEM_H__
#define __MOTION_SYSTEM_H__

#include "system/system.hpp"

namespace Jackbengine {

class MotionSystem : public System
{
public:
    MotionSystem();
    ~MotionSystem() override;

    void update(float delta) override;

protected:
    bool hasRequiredComponents(Entity *entity) override;
};

} // namespace Jackbengine

#endif // __MOTION_SYSTEM_H__
