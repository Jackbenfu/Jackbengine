//
//  textComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 14/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_COMPONENT_H__
#define __TEXT_COMPONENT_H__

#include <string>
#include "component/component.h"
#include "core/render/color.h"
#include "core/render/font.h"
#include "core/math/rect.h"
#include "core/render/renderer.h"
#include "core/render/texture.h"

NS_BEGIN_JKB

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

class TextComponent :
    public Component,
    public TypedObject<TextComponent>
{
public:
    TextComponent();
    ~TextComponent();

    bool load(const Renderer *renderer, const char *file, uint size);

    const string& getText() const;
    void setText(const string& text);

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
    string m_text;

    int m_topWhiteSpace = 0;
    int m_bottomWhiteSpace = 0;
    int m_rightWhiteSpace = 0;
    int m_height = 0;

    Recti m_boundingRect;
    TextLayout m_layout = TextLayout::LeftTop;
};

NS_END_JKB

#endif // __TEXT_COMPONENT_H__
