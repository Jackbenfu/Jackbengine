//
// velocityComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __VELOCITY_COMPONENT_2_H__
#define __VELOCITY_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class VelocityComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(VelocityComponent2)

public:
    VelocityComponent2() = default;
    VelocityComponent2(float x, float y);

    ~VelocityComponent2() override = default;

    const Vec2f& get() const;
    void set(float x, float y);

    float x() const;
    void setX(float x);

    float y() const;
    void setY(float y);

private:
    Vec2f m_velocity;
};

using Velocity = VelocityComponent2;

} // namespace Jackbengine

#endif // __VELOCITY_COMPONENT_2_H__
