//
//  system.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "core/type/typedObject.h"
#include "entity/entityManager.h"

NS_BEGIN_JKB
NS_STD

class System
{
    friend class SystemManager;

protected:
    System();
    virtual ~System();

    EntityManager* entityManager() const;
    EntityManager* em() const;

    vector<Entity*> m_entities;

private:
    virtual void update(float delta) = 0;
    virtual bool hasRequiredComponents(Entity *entity) = 0;

    bool isEnabled() const;
    void enable();
    void disable();

    bool addEntity(Entity *entity);
    bool removeEntity(Entity *entity);

    void setEntityManager(EntityManager *entityManager);

    EntityManager *m_entityManager = nullptr;
    bool m_enabled = true;
};

NS_END_JKB

#endif // __SYSTEM_H__
