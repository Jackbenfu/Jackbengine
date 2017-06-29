//
// colorComponent.h
// jackbengine
//
// Created by Damien Bendejacq on 10/05/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_COMPONENT_H__
#define __COLOR_COMPONENT_H__

#include "component/component.h"
#include "core/render/color.h"

NS_BEGIN_JKB

class ColorComponent :
    public Component,
    public TypedObject<ColorComponent>
{
public:
    ColorComponent();
    ~ColorComponent();

    Color getColor() const;

    void setColor(Color color);
    void setColor(byte red, byte green, byte blue, byte alpha);
    void setColor(byte red, byte green, byte blue);

    byte getRed() const;
    void setRed(byte value);

    byte getGreen() const;
    void setGreen(byte value);

    byte getBlue() const;
    void setBlue(byte value);

    byte getAlpha() const;
    void setAlpha(byte value);

private:
    Color m_color;
};

NS_END_JKB

#endif // __COLOR_COMPONENT_H__
