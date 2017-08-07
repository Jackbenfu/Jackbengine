//
// colorComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 01/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COLOR_COMPONENT_2_H__
#define __COLOR_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/render/color.hpp"

namespace Jackbengine {

class ColorComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(ColorComponent2)

public:
    explicit ColorComponent2(Color color);
    ColorComponent2(byte red, byte green, byte blue, byte alpha);
    ColorComponent2(byte red, byte green, byte blue);

    ~ColorComponent2() override = default;

    Color getColor() const;

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

} // namespace Jackbengine

#endif // __COLOR_COMPONENT_2_H__
