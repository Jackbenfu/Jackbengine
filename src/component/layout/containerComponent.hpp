//
// containerComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 26/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __CONTAINER_COMPONENT_H__
#define __CONTAINER_COMPONENT_H__

#include "component/component.hpp"
#include "core/math/rect.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class ContainerComponent : public Component
{
public:
    ContainerComponent();
    ~ContainerComponent();

    const Recti& getRect() const;
    void setRect(int x, int y, int w, int h);

    bool contains(float x, float y) const;
    bool contains(const Vec2i& point) const;
    bool contains(const Vec2f& point) const;

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

private:
    Recti m_rect;
};

} // namespace Jackbengine

#endif // __CONTAINER_COMPONENT_H__
