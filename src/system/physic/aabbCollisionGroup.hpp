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
        : _tag1(nullptr), _tag2(nullptr)
    {
        // Nothing
    }

    AABBCollisionGroup(const char *tag1, const char *tag2)
        : _tag1(tag1), _tag2(tag2)
    {
        // Nothing
    }

    ~AABBCollisionGroup() = default;

    const std::string& getTag1() const { return _tag1; }
    const std::string& getTag2() const { return _tag2; }

private:
    std::string _tag1;
    std::string _tag2;
};

} // namespace Jackbengine

#endif // __AABB_COLLISION_GROUP_H__
