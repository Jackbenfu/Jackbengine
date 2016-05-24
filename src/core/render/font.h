//
//  font.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __FONT_H__
#define __FONT_H__

#include "common.h"

NS_BEGIN_JKB

class FontImpl;

class Font
{
public:
    virtual ~Font();

    virtual bool loadFromFile(const char *file, int size) = 0;
    virtual bool loadFromMemory(const void *data, size_t dataSize, int size) = 0;

    virtual bool getGlyphMetrics(
        ushort glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const = 0;

    virtual bool getGlyphMinX(ushort glyph, int *minX) const = 0;
    virtual bool getGlyphMaxX(ushort glyph, int *maxX) const = 0;
    virtual bool getGlyphMinY(ushort glyph, int *minY) const = 0;
    virtual bool getGlyphMaxY(ushort glyph, int *maxY) const = 0;
    virtual bool getGlyphAdvance(ushort glyph, int *advance) const = 0;

    virtual int getAscent() const = 0;
    virtual int getDescent() const = 0;
    virtual int getLineSkip() const = 0;

    static Font* create();

protected:
    Font();
};

NS_END_JKB

#endif // __FONT_H__
