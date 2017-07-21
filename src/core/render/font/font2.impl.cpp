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

    m_font = TTF_OpenFontRW(sdlRwops->getInternalObject(), 0, size);
    if (nullptr == m_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

Font2::Impl::~Impl()
{
    TTF_CloseFont(m_font);
}

void Font2::Impl::getGlyphMetrics(
    ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
    if (TTF_GlyphMetrics(m_font, glyph, minX, maxX, minY, maxY, advance) < 0)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

int Font2::Impl::getAscent() const
{
    return TTF_FontAscent(m_font);
}

int Font2::Impl::getDescent() const
{
    return TTF_FontDescent(m_font);
}

int Font2::Impl::getLineSkip() const
{
    return TTF_FontLineSkip(m_font);
}

TTF_Font* Font2::Impl::getInternalObject() const
{
    return m_font;
}
