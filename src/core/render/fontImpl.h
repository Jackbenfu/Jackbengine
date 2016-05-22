//
//  fontImpl.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __FONT_IMPL_H__
#define __FONT_IMPL_H__

#include "font.h"

NS_BEGIN_JKB

class FontImpl : public Font
{
    friend class Font;

public:
    ~FontImpl();

    bool loadFromFile(const char *file, int size) override;
    bool loadFromMemory(const void *data, size_t dataSize, int size) override;

    bool getGlyphMetrics(ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const override;
    bool getGlyphMinX(ushort glyph, int *minX) const override;
    bool getGlyphMaxX(ushort glyph, int *maxX) const override;
    bool getGlyphMinY(ushort glyph, int *minY) const override;
    bool getGlyphMaxY(ushort glyph, int *maxY) const override;
    bool getGlyphAdvance(ushort glyph, int *advance) const override;

    int getAscent() const override;
    int getDescent() const override;
    int getLineSkip() const override;

    TTF_Font* getRawFont() const;

private:
    FontImpl();

    TTF_Font *m_font = nullptr;
    bool m_isInitialized = false;
};

NS_END_JKB

#endif // __FONT_IMPL_H__
