//
// motionSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 09/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __MOTION_SYSTEM_2_H__
#define __MOTION_SYSTEM_2_H__

#include "system/system2.hpp"

namespace Jackbengine {

class MotionSystem2 final : public System2
{
    DISALLOW_COPY_AND_MOVE(MotionSystem2)

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;
};

} // namespace Jackbengine

#endif // __MOTION_SYSTEM_2_H__
