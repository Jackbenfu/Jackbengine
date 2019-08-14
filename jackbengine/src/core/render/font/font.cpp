//
// font.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "pch.h"
#include "font.h"
#include "core/sdl/io/sdlRwops.h"

namespace Jackbengine {

Font::Font(const std::string &file, int size)
{
    m_font = TTF_OpenFont(file.c_str(), size);
    if (nullptr == m_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

Font::Font(const void *data, size_t dataSize, int size)
{
    const auto sdlRwops = std::make_unique<SdlRwops>(data, dataSize);

    m_font = TTF_OpenFontRW((SDL_RWops *) sdlRwops->internalObject(), 1, size);
    if (nullptr == m_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

Font::~Font()
{
    TTF_CloseFont(m_font);
}

void Font::glyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
    if (TTF_GlyphMetrics(m_font, glyph, minX, maxX, minY, maxY, advance) < 0)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

void Font::glyphMinX(ushort glyph, int *minX) const
{
    int maxX;
    int minY;
    int maxY;
    int advance;

    glyphMetrics(glyph, minX, &maxX, &minY, &maxY, &advance);
}

void Font::glyphMaxX(ushort glyph, int *maxX) const
{
    int minX;
    int minY;
    int maxY;
    int advance;

    return glyphMetrics(glyph, &minX, maxX, &minY, &maxY, &advance);
}

void Font::glyphMinY(ushort glyph, int *minY) const
{
    int minX;
    int maxX;
    int maxY;
    int advance;

    return glyphMetrics(glyph, &minX, &maxX, minY, &maxY, &advance);
}

void Font::glyphMaxY(ushort glyph, int *maxY) const
{
    int minX;
    int maxX;
    int minY;
    int advance;

    return glyphMetrics(glyph, &minX, &maxX, &minY, maxY, &advance);
}

void Font::glyphAdvance(ushort glyph, int *advance) const
{
    int minX;
    int maxX;
    int minY;
    int maxY;

    glyphMetrics(glyph, &minX, &maxX, &minY, &maxY, advance);
}

int Font::ascent() const
{
    return TTF_FontAscent(m_font);
}

int Font::descent() const
{
    return TTF_FontDescent(m_font);
}

int Font::lineSkip() const
{
    return TTF_FontLineSkip(m_font);
}

}
