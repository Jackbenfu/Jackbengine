//
//  textComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 14/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "textComponent.h"

TextComponent::TextComponent()
{
}

TextComponent::~TextComponent()
{
    DELETE_SAFE(m_font);
    DELETE_SAFE(m_texture);
}

bool TextComponent::loadFromFile(const Renderer *renderer, const char *file, uint size)
{
    bool result = false;

    if (renderer && !m_font)
    {
        m_renderer = renderer;

        m_boundingRect.w = renderer->getWidth();
        m_boundingRect.h = renderer->getHeight();

        m_font = Font::create();
        if (m_font)
        {
            result = m_font->loadFromFile(file, size);

            m_isLoaded = result;
            refreshTexture();
        }
    }

    return result;
}

bool TextComponent::loadFromMemory(
    const Renderer *renderer, const void *data, size_t dataSize, int size)
{
    bool result = false;

    if (renderer && !m_font)
    {
        m_renderer = renderer;

        m_boundingRect.w = renderer->getWidth();
        m_boundingRect.h = renderer->getHeight();

        m_font = Font::create();
        if (m_font)
        {
            result = m_font->loadFromMemory(data, dataSize, size);

            m_isLoaded = result;
            refreshTexture();
        }
    }

    return result;
}

const string& TextComponent::getText() const
{
    return m_text;
}

void TextComponent::setText(const string& text)
{
    if (0 != m_text.compare(text))
    {
        m_text = text;

        refreshTexture();
    }
}

Color TextComponent::getForeground() const
{
    return m_foreground;
}

void TextComponent::setForeground(Color color)
{
    m_foreground = color;

    refreshTexture();
}

void TextComponent::setForeground(byte r, byte g, byte b)
{
    m_foreground = Color(r, g, b);

    refreshTexture();
}

void TextComponent::setForeground(byte r, byte g, byte b, byte a)
{
    m_foreground = Color(r, g, b, a);

    refreshTexture();
}

float TextComponent::getWidth() const
{
    return m_texture ? static_cast<float>(m_texture->getWidth()) : -1.0f;
}

float TextComponent::getHeight() const
{
    return static_cast<float>(m_height);
}

int TextComponent::getTopWhiteSpace() const
{
    return m_topWhiteSpace;
}

int TextComponent::getBottomWhiteSpace() const
{
    return m_bottomWhiteSpace;
}

int TextComponent::getRightWhiteSpace() const
{
    return m_rightWhiteSpace;
}

TextLayout TextComponent::getLayout() const
{
    return m_layout;
}

void TextComponent::setLayout(TextLayout layout)
{
    m_layout = layout;
}

const Recti& TextComponent::getBoundingRect() const
{
    return m_boundingRect;
}

void TextComponent::setBoundingRect(int x, int y, int w, int h)
{
    m_boundingRect.x = x;
    m_boundingRect.y = y;
    m_boundingRect.w = w;
    m_boundingRect.h = h;
}

Texture* TextComponent::getTexture() const
{
    return m_texture;
}

void TextComponent::refreshTexture()
{
    if (m_isLoaded && !m_text.empty())
    {
        DELETE_SAFE(m_texture);

        m_texture = Texture::create();
        if (m_texture->loadFromFont(m_renderer, m_font, m_foreground, m_text))
        {
            int glyphMaxY = 0;
            int lastGlyphAdvance = 0;
            int lastGlyphMaxX = 0;
            for (int i = 0; i < static_cast<int>(m_text.length()); ++i)
            {
                int glyphY;
                if (static_cast<int>(m_text.length()) - 1 > i)
                {
                    m_font->getGlyphMaxY((ushort)m_text[i], &glyphY);
                }
                else
                {
                    int minX;
                    int minY;
                    m_font->getGlyphMetrics((ushort)m_text[i], &minX, &lastGlyphMaxX,
                        &minY, &glyphY, &lastGlyphAdvance);
                }

                if (glyphY > glyphMaxY)
                {
                    glyphMaxY = glyphY;
                }
            }

            m_bottomWhiteSpace = abs(m_font->getDescent());
            m_topWhiteSpace = m_font->getLineSkip() - glyphMaxY - m_bottomWhiteSpace;
            m_rightWhiteSpace = lastGlyphAdvance - lastGlyphMaxX;

            m_height = m_font->getLineSkip();
        }
    }
}
