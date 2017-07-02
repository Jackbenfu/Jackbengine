//
// aabbCollisionSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 24/01/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __AABB_COLLISION_SYSTEM_H__
#define __AABB_COLLISION_SYSTEM_H__

#include <string>
#include <vector>
#include "system/system.hpp"
#include "aabbCollisionGroup.hpp"

namespace Jackbengine {

enum class AABBCollisionSide
{
    Top,
    Right,
    Bottom,
    Left
};

using AABBCollisionCallback = bool(*)(
    float delta,
    Entity *e1,
    Entity *e2,
    AABBCollisionSide collisionSide
);

class AABBCollisionSystem : public System
{
public:
    AABBCollisionSystem();
    ~AABBCollisionSystem() override;

    void update(float delta) override;

    bool addCollisionGroup(const char *tag1, const char *tag2);
    bool removeCollisionGroup(const char *tag1, const char *tag2);

    bool setCallback(AABBCollisionCallback callback);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    std::vector<AABBCollisionGroup*> m_groups;
    AABBCollisionCallback m_callback = nullptr;

    void testCollision(float delta, Entity *entity1, Entity *entity2) const;
};

} // namespace Jackbengine

#endif // __AABB_COLLISION_SYSTEM_H__
