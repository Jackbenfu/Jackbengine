//
// aabbCollisionGroup.hpp
// jackbengine
//
// Created by Damien Bendejacq on 02/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __AABB_COLLISION_GROUP_H__
#define __AABB_COLLISION_GROUP_H__

#include "common.hpp"

namespace Jackbengine {

class AABBCollisionGroup
{
public:
    AABBCollisionGroup()
        : AABBCollisionGroup {nullptr, nullptr}
    { }

    AABBCollisionGroup(const char *tag1, const char *tag2)
        : m_tag1(tag1), m_tag2(tag2)
    { }

    ~AABBCollisionGroup() = default;

    const std::string& tag1() const { return m_tag1; }
    const std::string& tag2() const { return m_tag2; }

private:
    std::string m_tag1;
    std::string m_tag2;
};

} // namespace Jackbengine

#endif // __AABB_COLLISION_GROUP_H__
