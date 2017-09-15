//
// containerComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __CONTAINER_COMPONENT_2_H__
#define __CONTAINER_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/math/rect.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class ContainerComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(ContainerComponent2)

public:
    ContainerComponent2(int x, int y, int w, int h);
    ~ContainerComponent2() override = default;

    const Recti& rect() const;
    void setRect(int x, int y, int w, int h);

    bool contains(float x, float y) const;
    bool contains(const Vec2i& point) const;
    bool contains(const Vec2f& point) const;

    int x() const;
    int y() const;
    int width() const;
    int height() const;

private:
    Recti m_rect;
};

using Container = ContainerComponent2;

} // namespace Jackbengine

#endif // __CONTAINER_COMPONENT_2_H__
