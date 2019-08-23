//
// font.h
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __FONT_H__
#define __FONT_H__

#include "core/sdl/sdl.h"

namespace Jackbengine {

class Font
{
    friend class Surface;

public:
    Font(const std::string &file, int size);
    Font(const void *data, size_t dataSize, int size);

    ~Font();

    void glyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const;

    void glyphMinX(ushort glyph, int *minX) const;
    void glyphMaxX(ushort glyph, int *maxX) const;
    void glyphMinY(ushort glyph, int *minY) const;
    void glyphMaxY(ushort glyph, int *maxY) const;
    void glyphAdvance(ushort glyph, int *advance) const;

    [[nodiscard]] int ascent() const;
    [[nodiscard]] int descent() const;
    [[nodiscard]] int lineSkip() const;

private:
    TTF_Font *m_font {nullptr};
};

}

#endif // __FONT_H__
