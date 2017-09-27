//
// system2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_2_H__
#define __SYSTEM_2_H__

#include <map>
#include "entity/entityManager.hpp"

namespace Jackbengine {

class System2
{
    friend class SystemManager;

    DISALLOW_COPY_AND_MOVE(System2)

public:
    System2() = default;
    virtual ~System2() = default;

protected:
    std::map<Entity2, ComponentCollection*> m_entities;

private:
    virtual void frame(float delta) = 0;
    virtual bool hasRequiredComponents(ComponentCollection& components) const = 0;

    void addEntity(Entity2 entity, ComponentCollection& components);
    void removeEntity(Entity2 entity);
};

} // namespace Jackbengine

#endif // __SYSTEM_2_H__
