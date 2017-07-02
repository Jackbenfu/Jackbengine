//
// boxShapeComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 05/02/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __BOX_SHAPE_COMPONENT_H__
#define __BOX_SHAPE_COMPONENT_H__

#include "component/component.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class BoxShapeComponent : public Component
{
public:
    BoxShapeComponent();
    ~BoxShapeComponent();

    float getWidth() const;
    float getHeight() const;
    const Vec2f& getSize() const;

    void setWidth(float width);
    void setHeight(float height);
    void setSize(float width, float height);

private:
    Vec2f m_vector;
};

} // namespace Jackbengine

#endif //__BOX_SHAPE_COMPONENT_H__
