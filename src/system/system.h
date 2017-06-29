//
// system.h
// jackbengine
//
// Created by Damien Bendejacq on 18/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <vector>
#include "core/type/typedObject.h"
#include "entity/entity.h"

NS_BEGIN_JKB
NS_STD

class System
{
    friend class EcsManager;

protected:
    System();
    virtual ~System();

    vector<Entity*> m_entities;

private:
    virtual void update(float delta) = 0;
    virtual bool hasRequiredComponents(Entity *entity) = 0;

    bool isEnabled() const;
    void enable();
    void disable();

    bool addEntity(Entity *entity);
    bool removeEntity(Entity *entity);

    bool m_enabled = true;
};

NS_END_JKB

#endif // __SYSTEM_H__
