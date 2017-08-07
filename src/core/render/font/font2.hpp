//
// font2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __FONT_2_H__
#define __FONT_2_H__

#include <memory>
#include "common.hpp"

namespace Jackbengine {

class Font2
{
    friend class SdlSurface;

    DISALLOW_COPY_AND_MOVE(Font2)

public:
    Font2(const std::string& file, int size);
    Font2(const void *data, size_t dataSize, int size);

    ~Font2();

    void getGlyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const;

    void getGlyphMinX(ushort glyph, int *minX) const;
    void getGlyphMaxX(ushort glyph, int *maxX) const;
    void getGlyphMinY(ushort glyph, int *minY) const;
    void getGlyphMaxY(ushort glyph, int *maxY) const;
    void getGlyphAdvance(ushort glyph, int *advance) const;

    int getAscent() const;
    int getDescent() const;
    int getLineSkip() const;

private:
    void* getInternalObject() const;

    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __FONT_2_H__
