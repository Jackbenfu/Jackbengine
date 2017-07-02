//
// textComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 14/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_COMPONENT_H__
#define __TEXT_COMPONENT_H__

#include <string>
#include "component/component.hpp"
#include "core/render/color.hpp"
#include "core/render/font.hpp"
#include "core/math/rect.hpp"
#include "core/render/renderer.hpp"
#include "core/render/texture.hpp"

namespace Jackbengine {

enum class TextLayout
{
    LeftTop,
    LeftCenter,
    LeftBottom,
    CenterTop,
    CenterCenter,
    CenterBottom,
    RightTop,
    RightCenter,
    RightBottom
};

class TextComponent : public Component
{
public:
    TextComponent();
    ~TextComponent();

    bool setFontFromFile(const Renderer *renderer, const char *file, int size);
    bool setFontFromMemory(const Renderer *renderer, const void *data, size_t dataSize, int size);

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

    TextLayout getLayout() const;
    void setLayout(TextLayout layout);

    const Recti& getBoundingRect() const;
    void setBoundingRect(int x, int y, int w, int h);

    Texture* getTexture() const;

private:
    void refreshTexture();

    bool m_isLoaded = false;

    const Renderer *m_renderer = nullptr;
    Font *m_font = nullptr;
    Texture *m_texture = nullptr;
    Color m_foreground = Color(Color_White);
    std::string m_text;

    int m_topWhiteSpace = 0;
    int m_bottomWhiteSpace = 0;
    int m_rightWhiteSpace = 0;
    int m_height = 0;

    Recti m_boundingRect;
    TextLayout m_layout = TextLayout::LeftTop;
};

} // namespace Jackbengine

#endif // __TEXT_COMPONENT_H__
