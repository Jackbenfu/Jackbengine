//
// velocityComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/05/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __VELOCITY_COMPONENT_H__
#define __VELOCITY_COMPONENT_H__

#include "component/component.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class VelocityComponent : public Component
{
public:
    VelocityComponent();
    ~VelocityComponent();

    const Vec2f& getVelocity() const;
    void set(float x, float y);

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

private:
    Vec2f m_velocity = Vec2f(0.0f, 0.0f);
};

} // namespace Jackbengine

#endif // __VELOCITY_COMPONENT_H__
