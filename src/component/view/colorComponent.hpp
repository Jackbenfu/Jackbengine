//
// colorComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 01/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_COMPONENT_H__
#define __COLOR_COMPONENT_H__

#include "component/component.hpp"
#include "core/render/color.hpp"

namespace Jackbengine {

class ColorComponent : public Component
{
public:
    explicit ColorComponent(Color color);
    ColorComponent(byte red, byte green, byte blue, byte alpha);
    ColorComponent(byte red, byte green, byte blue);

    ~ColorComponent() override = default;

    Color getColor() const;

    byte red() const;
    void setRed(byte value);

    byte green() const;
    void setGreen(byte value);

    byte blue() const;
    void setBlue(byte value);

    byte alpha() const;
    void setAlpha(byte value);

private:
    Color m_color;
};

}

#endif // __COLOR_COMPONENT_H__
