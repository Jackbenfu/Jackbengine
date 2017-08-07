//
// textComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 05/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_COMPONENT_2_H__
#define __TEXT_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/render/color.hpp"
#include "core/render/font/font2.hpp"
#include "core/math/rect.hpp"
#include "core/render/renderer/renderer2.hpp"
#include "core/render/texture/texture2.hpp"

namespace Jackbengine {

enum class TextLayout2
{
    LeftTop,
    LeftCenter,
    LeftBottom,
    CenterTop,
    CenterCenter,
    CenterBottom,
    RightTop,
    RightCenter,
    RightBottom,
};

class TextComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(TextComponent2)

public:
    TextComponent2(const Renderer2& renderer, const Font2& font, const std::string& text);
    TextComponent2(const Renderer2& renderer, const Font2& font, const std::string& text, TextLayout2 layout);
    TextComponent2(const Renderer2& renderer, const Font2& font,
                   const std::string& text, TextLayout2 layout, Color foreground);

    ~TextComponent2() override = default;

    const std::string& getText() const;
    void setText(const std::string& text);

    Color getForeground() const;
    void setForeground(Color color);
    void setForeground(byte r, byte g, byte b);
    void setForeground(byte r, byte g, byte b, byte a);

    float getWidth() const;
    float getHeight() const;

    int getTopWhiteSpace() const;
    int getBottomWhiteSpace() const;
    int getRightWhiteSpace() const;

    TextLayout2 getLayout() const;
    void setLayout(TextLayout2 layout);

private:
    void refreshTexture();

    const Renderer2& m_renderer;
    const Font2& m_font;

    std::string m_text;
    TextLayout2 m_layout {TextLayout2::LeftTop};
    Color m_foreground {Color_White};

    std::unique_ptr<Texture2> m_texture;

    int m_topWhiteSpace {0};
    int m_bottomWhiteSpace {0};
    int m_rightWhiteSpace {0};
};

} // namespace Jackbengine

#endif // __TEXT_COMPONENT_2_H__
