//
//  motionSystem.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/05/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __MOTION_SYSTEM_H__
#define __MOTION_SYSTEM_H__

#include "system/system.h"

NS_BEGIN_JKB

class MotionSystem :
    public System,
    public TypedObject<MotionSystem>
{
public:
    MotionSystem();
    ~MotionSystem();

    void update(float delta) override;

protected:
    bool hasRequiredComponents(Entity *entity) override;
};

NS_END_JKB

#endif // __MOTION_SYSTEM_H__
