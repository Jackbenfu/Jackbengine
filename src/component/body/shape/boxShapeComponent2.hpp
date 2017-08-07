//
// boxShapeComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 28/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __BOX_SHAPE_COMPONENT_2_H__
#define __BOX_SHAPE_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/math/vector2d.hpp"

namespace Jackbengine {

class BoxShapeComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(BoxShapeComponent2)

public:
    BoxShapeComponent2() = default;
    BoxShapeComponent2(float width, float height);

    ~BoxShapeComponent2() override = default;

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

#endif // __BOX_SHAPE_COMPONENT_2_H__
