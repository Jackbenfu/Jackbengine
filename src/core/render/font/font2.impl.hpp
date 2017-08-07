//
// font2.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __FONT_2_IMPL_H__
#define __FONT_2_IMPL_H__

#include "font2.hpp"
#include "platform.hpp"

namespace Jackbengine {

class Font2::Impl
{
public:
    Impl(const std::string& file, int size);
    Impl(const void *data, size_t dataSize, int size);

    ~Impl();

    void getGlyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const;

    void getGlyphMinX(ushort glyph, int *minX) const;
    void getGlyphMaxX(ushort glyph, int *maxX) const;
    void getGlyphMinY(ushort glyph, int *minY) const;
    void getGlyphMaxY(ushort glyph, int *maxY) const;
    void getGlyphAdvance(ushort glyph, int *advance) const;

    int getAscent() const;
    int getDescent() const;
    int getLineSkip() const;

    TTF_Font* getInternalObject() const;

private:
    TTF_Font *m_font {nullptr};
};

} // namespace Jackbengine

#endif // __FONT_2_IMPL_H__
