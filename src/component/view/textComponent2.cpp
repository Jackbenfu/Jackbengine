//
// textComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 05/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "textComponent2.hpp"
#include "textComponent.hpp"

using namespace Jackbengine;

TextComponent2::TextComponent2(const Renderer2& renderer, const Font2& font,
                               const std::string& text)
    : m_renderer {renderer},
      m_font {font},
      m_text {text}
{
    refreshTexture();
}

TextComponent2::TextComponent2(const Renderer2& renderer, const Font2& font,
                               const std::string& text, TextLayout2 layout)
    : m_renderer {renderer},
      m_font {font},
      m_text {text},
      m_layout {layout}
{
    refreshTexture();
}

TextComponent2::TextComponent2(const Renderer2& renderer, const Font2& font,
                               const std::string& text, TextLayout2 layout, Color foreground)
    : m_renderer {renderer},
      m_font {font},
      m_text {text},
      m_layout {layout},
      m_foreground {foreground}
{
    refreshTexture();
}

const std::string& TextComponent2::getText() const
{
    return m_text;
}

void TextComponent2::setText(const std::string& text)
{
    m_text = text;

    refreshTexture();
}

Color TextComponent2::getForeground() const
{
    return m_foreground;
}

void TextComponent2::setForeground(Color color)
{
    m_foreground = color;

    refreshTexture();
}

void TextComponent2::setForeground(byte r, byte g, byte b)
{
    m_foreground = Color(r, g, b);

    refreshTexture();
}

void TextComponent2::setForeground(byte r, byte g, byte b, byte a)
{
    m_foreground = Color(r, g, b, a);

    refreshTexture();
}

float TextComponent2::getWidth() const
{
    return m_texture->getWidth();
}

float TextComponent2::getHeight() const
{
    return m_texture->getHeight();
}

int TextComponent2::getTopWhiteSpace() const
{
    return m_topWhiteSpace;
}

int TextComponent2::getBottomWhiteSpace() const
{
    return m_bottomWhiteSpace;
}

int TextComponent2::getRightWhiteSpace() const
{
    return m_rightWhiteSpace;
}

TextLayout2 TextComponent2::getLayout() const
{
    return m_layout;
}

void TextComponent2::setLayout(TextLayout2 layout)
{
    m_layout = layout;
}

Texture2& TextComponent2::getTexture() const
{
    return *m_texture;
}

void TextComponent2::refreshTexture()
{
    m_texture = std::make_unique<Texture2>(m_renderer, m_font, m_text, m_foreground);

    auto glyphMaxY = 0;
    auto lastGlyphAdvance = 0;
    auto lastGlyphMaxX = 0;
    for (auto i = 0; i < m_text.length(); ++i)
    {
        int glyphY;
        if (m_text.length() - 1 > i)
        {
            m_font.getGlyphMaxY((ushort)m_text[i], &glyphY);
        }
        else
        {
            int minX;
            int minY;
            m_font.getGlyphMetrics((ushort)m_text[i], &minX, &lastGlyphMaxX, &minY, &glyphY, &lastGlyphAdvance);
        }

        if (glyphY > glyphMaxY)
        {
            glyphMaxY = glyphY;
        }
    }

    m_bottomWhiteSpace = abs(m_font.getDescent());
    m_topWhiteSpace = m_font.getLineSkip() - glyphMaxY - m_bottomWhiteSpace;
    m_rightWhiteSpace = lastGlyphAdvance - lastGlyphMaxX;
}
