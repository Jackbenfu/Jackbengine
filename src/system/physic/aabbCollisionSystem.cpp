//
//  aabbCollisionSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 24/01/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "aabbCollisionSystem.h"
#include "component/body/shape/boxShapeComponent.h"
#include "component/body/transformComponent.h"
#include "component/body/velocityComponent.h"
#include "component/misc/tagComponent.h"

AABBCollisionSystem::AABBCollisionSystem()
{
}

AABBCollisionSystem::~AABBCollisionSystem()
{
    for (auto group : m_groups)
    {
        DELETE_SAFE(group);
    }
    m_groups.clear();
}

void AABBCollisionSystem::update(float delta)
{
    for (auto group : m_groups)
    {
        string ltag1 = group->getTag1();
        string ltag2 = group->getTag2();

        for (auto entity1 : m_entities)
        {
            if (em()->isEntityEnabled(entity1))
            {
                TagComponent *tag1 = em()->getComponent<TagComponent>(entity1);
                if (tag1->getTag() == ltag1)
                {
                    for (auto entity2 : m_entities)
                    {
                        if (em()->isEntityEnabled(entity2) && entity1 != entity2)
                        {
                            TagComponent *tag2 = em()->getComponent<TagComponent>(entity2);
                            if (tag2->getTag() == ltag2)
                            {
                                testCollision(delta, entity1, entity2);
                            }
                        }
                    }
                }
            }
        }
    }
}

bool AABBCollisionSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponent<BoxShapeComponent>(entity) &&
        em()->getComponent<TagComponent>(entity) &&
        em()->getComponent<TransformComponent>(entity) &&
        em()->getComponent<VelocityComponent>(entity);
}

bool AABBCollisionSystem::addCollisionGroup(const char *tag1, const char *tag2)
{
    vector<AABBCollisionGroup*>::const_iterator it = m_groups.begin();
    vector<AABBCollisionGroup*>::const_iterator itEnd = m_groups.end();

    while (it != itEnd)
    {
        string existingTag1 = (*it)->getTag1();
        string existingTag2 = (*it)->getTag2();

        if (existingTag1 == tag1 && existingTag2 == tag2)
        {
            return false;
        }

        ++it;
    }

    m_groups.push_back(new AABBCollisionGroup(tag1, tag2));

    return true;
}

bool AABBCollisionSystem::removeCollisionGroup(const char *tag1, const char *tag2)
{
    vector<AABBCollisionGroup*>::const_iterator it = m_groups.begin();
    vector<AABBCollisionGroup*>::const_iterator itEnd = m_groups.end();

    while (it != itEnd)
    {
        string existingTag1 = (*it)->getTag1();
        string existingTag2 = (*it)->getTag2();

        if (existingTag1 == tag1 && existingTag2 == tag2)
        {
            m_groups.erase(it);
            return true;
        }

        ++it;
    }

    return false;
}

bool AABBCollisionSystem::setCallback(AABBCollisionCallback callback)
{
    if (callback)
    {
        m_callback = callback;
        return true;
    }

    return false;
}

void AABBCollisionSystem::testCollision(float delta, Entity *entity1, Entity *entity2) const
{
    TransformComponent *transform1 = em()->getComponent<TransformComponent>(entity1);
    float x1 = transform1->getPositionX();
    float y1 = transform1->getPositionY();

    BoxShapeComponent *boxShape1 = em()->getComponent<BoxShapeComponent>(entity1);
    float w1 = boxShape1->getWidth();
    float h1 = boxShape1->getHeight();

    TransformComponent *transform2 = em()->getComponent<TransformComponent>(entity2);
    float x2 = transform2->getPositionX();
    float y2 = transform2->getPositionY();

    BoxShapeComponent *boxShape2 = em()->getComponent<BoxShapeComponent>(entity2);
    float w2 = boxShape2->getWidth();
    float h2 = boxShape2->getHeight();

    if (!(x1 >= x2 + w2 || x1 + w1 <= x2 || y1 >= y2 + h2 || y1 + h1 <= y2))
    {
        VelocityComponent *velocity1 = em()->getComponent<VelocityComponent>(entity1);
        float vX1 = velocity1->getX();
        float vY1 = velocity1->getY();

        // Required move to go back to the position just before the collision
        float xToCollision = vX1 > 0.0f ? x2 - (x1 + w1) : (x2 + w2) - x1;
        float yToCollision = vY1 > 0.0f ? y2 - (y1 + h1) : (y2 + h2) - y1;

        // Same as above expressed in percentage (value from 0 to 1)
        float xOffsetToCollision = 0.0f == vX1 ?
        -numeric_limits<float>::infinity() : xToCollision / vX1;
        float yOffsetToCollision = 0.0f == vY1 ?
        -numeric_limits<float>::infinity() : yToCollision / vY1;

        // Collision time is the latest among the two axes
        float collisionTime = MAX(xOffsetToCollision, yOffsetToCollision);

        // Collision normals to find on which AABB side the collision occured
        float normalX;
        float normalY;
        AABBCollisionSide collisionSide;
        if (xOffsetToCollision > yOffsetToCollision)
        {
            normalX = xToCollision < 0.0f ? -1.0f : 1.0f;
            normalY = 0.0f;

            collisionSide = -1.0f == normalX ?
            AABBCollisionSide::Left : AABBCollisionSide::Right;
        }
        else
        {
            normalY = yToCollision < 0.0f ? -1.0f : 1.0f;
            normalX = 0.0f;

            collisionSide = -1.0f == normalY ?
            AABBCollisionSide::Top : AABBCollisionSide::Bottom;
        }

        // Position where the collision occured
        float xCollision = x1 + vX1 * collisionTime;
        float yCollision = y1 + vY1 * collisionTime;

        // Setting new position
        transform1->setPosition(xCollision, yCollision);

        bool collisionResolved = false;
        if (m_callback)
        {
            // If a callback is defined, we let the developer
            // choose the collision response behavior
            collisionResolved = m_callback(delta, entity1, entity2, collisionSide);
        }

        // Default behavior if collision not resolved by user
        if (!collisionResolved)
        {
            // Setting new velocity for "bounce" effect
            if (0.0f != normalX)
            {
                velocity1->setX(-vX1);
            }

            if (0.0f != normalY)
            {
                velocity1->setY(-vY1);
            }
        }
    }
}
