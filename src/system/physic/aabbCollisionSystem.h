//
// aabbCollisionSystem.h
// jackbengine
//
// Created by Damien Bendejacq on 24/01/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __AABB_COLLISION_SYSTEM_H__
#define __AABB_COLLISION_SYSTEM_H__

#include <string>
#include <vector>
#include <scene/scene.h>
#include "system/system.h"

NS_BEGIN_JKB
NS_STD

class AABBCollisionGroup
{
public:
    AABBCollisionGroup()
        : _tag1(nullptr), _tag2(nullptr)
    { }

    AABBCollisionGroup(const char *tag1, const char *tag2)
        : _tag1(tag1), _tag2(tag2)
    {
    }

    ~AABBCollisionGroup()
    { }

    const string& getTag1() const { return _tag1; }
    const string& getTag2() const { return _tag2; }

private:
    string _tag1;
    string _tag2;
};

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

class AABBCollisionSystem :
    public System,
    public TypedObject<AABBCollisionSystem>
{
public:
    AABBCollisionSystem();
    ~AABBCollisionSystem();

    void update(float delta) override;

    bool addCollisionGroup(const char *tag1, const char *tag2);
    bool removeCollisionGroup(const char *tag1, const char *tag2);

    bool setCallback(AABBCollisionCallback callback);

protected:
    bool hasRequiredComponents(Entity *entity) override;

private:
    vector<AABBCollisionGroup*> m_groups;
    AABBCollisionCallback m_callback = nullptr;

    void testCollision(float delta, Entity *entity1, Entity *entity2) const;
};

NS_END_JKB

#endif // __AABB_COLLISION_SYSTEM_H__
