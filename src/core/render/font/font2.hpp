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

    void glyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const;

    void glyphMinX(ushort glyph, int *minX) const;
    void glyphMaxX(ushort glyph, int *maxX) const;
    void glyphMinY(ushort glyph, int *minY) const;
    void glyphMaxY(ushort glyph, int *maxY) const;
    void glyphAdvance(ushort glyph, int *advance) const;

    int ascent() const;
    int descent() const;
    int lineSkip() const;

private:
    void* internalObject() const;

    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __FONT_2_H__
