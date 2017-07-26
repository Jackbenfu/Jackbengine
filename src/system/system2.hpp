//
// system2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_2_H__
#define __SYSTEM_2_H__

#include "entity/entityManager.hpp"

namespace Jackbengine {

class System2
{
    DISALLOW_COPY_AND_MOVE(System2)

public:
    explicit System2(const EntityManager& entityManager);
    virtual ~System2();

    virtual void update(float delta) = 0;

protected:
    inline const EntityManager& em() const;

private:
    const EntityManager& m_entityManager;
};

} // namespace Jackbengine

#endif // __SYSTEM_2_H__
