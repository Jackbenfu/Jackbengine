//
// containerComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __CONTAINER_COMPONENT_H__
#define __CONTAINER_COMPONENT_H__

#include "component/component.hpp"
#include "core/math/rect.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class ContainerComponent : public Component
{
    DISALLOW_COPY_AND_MOVE(ContainerComponent)

public:
    ContainerComponent(float x, float y, float w, float h);
    ~ContainerComponent() override = default;

    const Rectf& rect() const;
    void setRect(float x, float y, float w, float h);

    const Vec2f position() const;
    void setPosition(float x, float y);

    bool contains(float x, float y) const;
    bool contains(const Vec2i& point) const;
    bool contains(const Vec2f& point) const;

    float x() const;
    float y() const;
    float width() const;
    float height() const;

private:
    Rectf m_rect;
};

using Container = ContainerComponent;

} // namespace Jackbengine

#endif // __CONTAINER_COMPONENT_H__
