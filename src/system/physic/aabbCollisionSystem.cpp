//
// aabbCollisionSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 24/01/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include <limits>
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
        auto ltag1 = group->getTag1();
        auto ltag2 = group->getTag2();

        for (auto entity1 : m_entities)
        {
            if (entity1->isEnabled())
            {
                auto tag1 = entity1->getComponentIfEnabled<TagComponent>();

                if (!tag1)
                {
                    continue;
                }

                if (tag1->getTag() == ltag1)
                {
                    for (auto entity2 : m_entities)
                    {
                        if (entity2->isEnabled() && entity1 != entity2)
                        {
                            auto tag2 = entity2->getComponentIfEnabled<TagComponent>();

                            if (!tag2)
                            {
                                continue;
                            }

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
    return entity->getComponentIfEnabled<BoxShapeComponent>() &&
        entity->getComponentIfEnabled<TagComponent>() &&
        entity->getComponentIfEnabled<TransformComponent>() &&
        entity->getComponentIfEnabled<VelocityComponent>();
}

bool AABBCollisionSystem::addCollisionGroup(const char *tag1, const char *tag2)
{
    auto it = m_groups.begin();
    auto itEnd = m_groups.end();

    while (it != itEnd)
    {
        auto existingTag1 = (*it)->getTag1();
        auto existingTag2 = (*it)->getTag2();

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
    auto it = m_groups.begin();
    auto itEnd = m_groups.end();

    while (it != itEnd)
    {
        auto existingTag1 = (*it)->getTag1();
        auto existingTag2 = (*it)->getTag2();

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
    auto transform1 = entity1->getComponentIfEnabled<TransformComponent>();
    auto x1 = transform1->getPositionX();
    auto y1 = transform1->getPositionY();

    auto boxShape1 = entity1->getComponentIfEnabled<BoxShapeComponent>();
    auto w1 = boxShape1->getWidth();
    auto h1 = boxShape1->getHeight();

    auto transform2 = entity2->getComponentIfEnabled<TransformComponent>();
    auto x2 = transform2->getPositionX();
    auto y2 = transform2->getPositionY();

    auto boxShape2 = entity2->getComponentIfEnabled<BoxShapeComponent>();
    auto w2 = boxShape2->getWidth();
    auto h2 = boxShape2->getHeight();

    if (!(x1 >= x2 + w2 || x1 + w1 <= x2 || y1 >= y2 + h2 || y1 + h1 <= y2))
    {
        auto velocity1 = entity1->getComponentIfEnabled<VelocityComponent>();
        auto vX1 = velocity1->getX();
        auto vY1 = velocity1->getY();

        // Required move to go back to the position just before the collision
        auto xToCollision = vX1 > 0.0f ? x2 - (x1 + w1) : (x2 + w2) - x1;
        auto yToCollision = vY1 > 0.0f ? y2 - (y1 + h1) : (y2 + h2) - y1;

        // Same as above expressed in percentage (value from 0 to 1)
        auto xOffsetToCollision = 0.0f == vX1 ?
            -numeric_limits<float>::infinity() : xToCollision / vX1;
        auto yOffsetToCollision = 0.0f == vY1 ?
            -numeric_limits<float>::infinity() : yToCollision / vY1;

        // Collision time is the latest among the two axes
        auto collisionTime = MAX(xOffsetToCollision, yOffsetToCollision);

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
        auto xCollision = x1 + vX1 * collisionTime;
        auto yCollision = y1 + vY1 * collisionTime;

        // Setting new position
        transform1->setPosition(xCollision, yCollision);

        auto collisionResolved = false;
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
