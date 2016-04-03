//
//  transformComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 30/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

#include "component/component.h"
#include "core/math/vector2d.h"

NS_BEGIN_JKB

class TransformComponent :
    public Component,
    public TypedObject<TransformComponent>
{
public:
    TransformComponent();
    ~TransformComponent();

    const Vec2f& getPosition() const;
    float getPositionX() const;
    float getPositionY() const;
    void setPosition(float x, float y);
    void setPositionX(float x);
    void setPositionY(float y);

    const Vec2f& getRotation() const;
    float getRotationX() const;
    float getRotationY() const;
    void setRotation(float x, float y);
    void setRotationX(float x);
    void setRotationY(float y);

    const Vec2f& getScale() const;
    float getScaleX() const;
    float getScaleY() const;
    void setScale(float x, float y);
    void setScaleX(float x);
    void setScaleY(float y);

private:
    Vec2f m_position = Vec2f(0.0f, 0.0f);
    Vec2f m_rotation = Vec2f(0.0f, 0.0f);
    Vec2f m_scale = Vec2f(1.0f, 1.0f);
};

NS_END_JKB

#endif // __TRANSFORM_COMPONENT_H__
