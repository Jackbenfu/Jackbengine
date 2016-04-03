//
//  containerComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 26/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __CONTAINER_COMPONENT_H__
#define __CONTAINER_COMPONENT_H__

#include "component/component.h"
#include "core/math/rect.h"
#include "core/math/vector2d.h"

NS_BEGIN_JKB

class ContainerComponent :
    public Component,
    public TypedObject<ContainerComponent>
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

NS_END_JKB

#endif // __CONTAINER_COMPONENT_H__
