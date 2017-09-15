//
// font2.impl.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "font2.impl.hpp"
#include "core/sdl/io/sdlRwops.hpp"

using namespace Jackbengine;

Font2::Impl::Impl(const std::string& file, int size)
{
    m_font = TTF_OpenFont(file.c_str(), size);
    if (nullptr == m_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

Font2::Impl::Impl(const void *data, size_t dataSize, int size)
{
    const auto sdlRwops = std::make_unique<SdlRwops>(data, dataSize);

    m_font = TTF_OpenFontRW(sdlRwops->internalObject(), 1, size);
    if (nullptr == m_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

Font2::Impl::~Impl()
{
    TTF_CloseFont(m_font);
}

void Font2::Impl::glyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
    if (TTF_GlyphMetrics(m_font, glyph, minX, maxX, minY, maxY, advance) < 0)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

void Font2::Impl::glyphMinX(ushort glyph, int *minX) const
{
    int maxX;
    int minY;
    int maxY;
    int advance;

    glyphMetrics(glyph, minX, &maxX, &minY, &maxY, &advance);
}

void Font2::Impl::glyphMaxX(ushort glyph, int *maxX) const
{
    int minX;
    int minY;
    int maxY;
    int advance;

    return glyphMetrics(glyph, &minX, maxX, &minY, &maxY, &advance);
}

void Font2::Impl::glyphMinY(ushort glyph, int *minY) const
{
    int minX;
    int maxX;
    int maxY;
    int advance;

    return glyphMetrics(glyph, &minX, &maxX, minY, &maxY, &advance);
}

void Font2::Impl::glyphMaxY(ushort glyph, int *maxY) const
{
    int minX;
    int maxX;
    int minY;
    int advance;

    return glyphMetrics(glyph, &minX, &maxX, &minY, maxY, &advance);
}

void Font2::Impl::glyphAdvance(ushort glyph, int *advance) const
{
    int minX;
    int maxX;
    int minY;
    int maxY;

    glyphMetrics(glyph, &minX, &maxX, &minY, &maxY, advance);
}

int Font2::Impl::ascent() const
{
    return TTF_FontAscent(m_font);
}

int Font2::Impl::descent() const
{
    return TTF_FontDescent(m_font);
}

int Font2::Impl::lineSkip() const
{
    return TTF_FontLineSkip(m_font);
}

TTF_Font* Font2::Impl::internalObject() const
{
    return m_font;
}
