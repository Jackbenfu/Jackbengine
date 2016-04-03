//
//  fontImpl.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "fontImpl.h"

FontImpl::FontImpl()
{
}

FontImpl::~FontImpl()
{
    TTF_CloseFont(m_font);
}

bool FontImpl::load(const char *file, int size)
{
    if (!m_isInitialized)
    {
        m_font = TTF_OpenFont(file, size);
        if (!m_font)
        {
            printf("%s\n", TTF_GetError());
            return false;
        }

        m_isInitialized = true;
        return true;
    }

    return false;
}

bool FontImpl::getGlyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
    return 0 < TTF_GlyphMetrics(m_font, glyph, minX, maxX, minY, maxY, advance);
}

bool FontImpl::getGlyphMinX(ushort glyph, int *minX) const
{
    int maxX;
    int minY;
    int maxY;
    int advance;

    return getGlyphMetrics(glyph, minX, &maxX, &minY, &maxY, &advance);
}

bool FontImpl::getGlyphMaxX(ushort glyph, int *maxX) const
{
    int minX;
    int minY;
    int maxY;
    int advance;

    return getGlyphMetrics(glyph, &minX, maxX, &minY, &maxY, &advance);
}

bool FontImpl::getGlyphMinY(ushort glyph, int *minY) const
{
    int minX;
    int maxX;
    int maxY;
    int advance;

    return getGlyphMetrics(glyph, &minX, &maxX, minY, &maxY, &advance);
}

bool FontImpl::getGlyphMaxY(ushort glyph, int *maxY) const
{
    int minX;
    int maxX;
    int minY;
    int advance;

    return getGlyphMetrics(glyph, &minX, &maxX, &minY, maxY, &advance);
}

bool FontImpl::getGlyphAdvance(ushort glyph, int *advance) const
{
    int minX;
    int maxX;
    int minY;
    int maxY;

    return getGlyphMetrics(glyph, &minX, &maxX, &minY, &maxY, advance);
}

int FontImpl::getAscent() const
{
    return TTF_FontAscent(m_font);
}

int FontImpl::getDescent() const
{
    return TTF_FontDescent(m_font);
}

int FontImpl::getLineSkip() const
{
    return TTF_FontLineSkip(m_font);
}

TTF_Font* FontImpl::getRawFont() const
{
    return m_font;
}
