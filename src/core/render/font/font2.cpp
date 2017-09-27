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
{ }

Font2::Font2(const void *data, size_t dataSize, int size)
    : m_impl {std::make_unique<Impl>(data, dataSize, size)}
{ }

Font2::~Font2() = default;

void Font2::glyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
    m_impl->glyphMetrics(glyph, minX, maxX, minY, maxY, advance);
}

void Font2::glyphMinX(ushort glyph, int *minX) const
{
    m_impl->glyphMinX(glyph, minX);
}

void Font2::glyphMaxX(ushort glyph, int *maxX) const
{
    m_impl->glyphMaxX(glyph, maxX);
}

void Font2::glyphMinY(ushort glyph, int *minY) const
{
    m_impl->glyphMinY(glyph, minY);
}

void Font2::glyphMaxY(ushort glyph, int *maxY) const
{
    m_impl->glyphMaxY(glyph, maxY);
}

void Font2::glyphAdvance(ushort glyph, int *advance) const
{
    m_impl->glyphMinX(glyph, advance);
}

int Font2::ascent() const
{
    return m_impl->ascent();
}

int Font2::descent() const
{
    return m_impl->descent();
}

int Font2::lineSkip() const
{
    return m_impl->lineSkip();
}

void* Font2::internalObject() const
{
    return m_impl->internalObject();
}
