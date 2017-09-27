//
// aabbCollisionSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __AABB_COLLISION_SYSTEM_2_H__
#define __AABB_COLLISION_SYSTEM_2_H__

#include <vector>
#include <string>
#include "system/system2.hpp"

namespace Jackbengine {

enum class AABBCollisionSide2
{
    Top,
    Right,
    Bottom,
    Left,
};

using AABBCollisionCallback2 = bool(*)(
    float delta,
    ComponentCollection& components1,
    ComponentCollection& components2,
    AABBCollisionSide2 collisionSide
);

class AABBCollisionSystem2 : public System2
{
    DISALLOW_COPY_AND_MOVE(AABBCollisionSystem2)

public:
    AABBCollisionSystem2() = default;
    ~AABBCollisionSystem2() override = default;

    void addGroup(const std::string& tag1, const std::string& tag2);
    void removeGroup(const std::string& tag1, const std::string& tag2);

    void setCallback(AABBCollisionCallback2 callback);

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    void testCollision(float delta, ComponentCollection& components1, ComponentCollection& components2) const;

    std::vector<std::pair<std::string, std::string>> m_groups;
    AABBCollisionCallback2 m_callback {nullptr};
};

} // namespace Jackbengine

#endif // __AABB_COLLISION_SYSTEM_2_H__
