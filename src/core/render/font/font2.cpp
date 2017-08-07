//
// font2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "font2.hpp"
#include "font2.impl.hpp"

using namespace Jackbengine;

Font2::Font2(const std::string& file, int size)
    : m_impl {std::make_unique<Impl>(file, size)}
{
    // Nothing
}

Font2::Font2(const void *data, size_t dataSize, int size)
    : m_impl {std::make_unique<Impl>(data, dataSize, size)}
{
    // Nothing
}

Font2::~Font2() = default;

void Font2::getGlyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
    m_impl->getGlyphMetrics(glyph, minX, maxX, minY, maxY, advance);
}

void Font2::getGlyphMinX(ushort glyph, int *minX) const
{
    m_impl->getGlyphMinX(glyph, minX);
}

void Font2::getGlyphMaxX(ushort glyph, int *maxX) const
{
    m_impl->getGlyphMaxX(glyph, maxX);
}

void Font2::getGlyphMinY(ushort glyph, int *minY) const
{
    m_impl->getGlyphMinY(glyph, minY);
}

void Font2::getGlyphMaxY(ushort glyph, int *maxY) const
{
    m_impl->getGlyphMaxY(glyph, maxY);
}

void Font2::getGlyphAdvance(ushort glyph, int *advance) const
{
    m_impl->getGlyphMinX(glyph, advance);
}

int Font2::getAscent() const
{
    return m_impl->getAscent();
}

int Font2::getDescent() const
{
    return m_impl->getDescent();
}

int Font2::getLineSkip() const
{
    return m_impl->getLineSkip();
}

void* Font2::getInternalObject() const
{
    return m_impl->getInternalObject();
}
