//
// font.h
// jackbengine
//
// Created by Damien Bendejacq on 13/07/2017.
//

#ifndef __FONT_H__
#define __FONT_H__

#include <string>

typedef struct _TTF_Font TTF_Font;

namespace Jackbengine::details {

class Font
{
    friend class Surface;

public:
    Font(const std::string &file, int size);
    Font(const void *data, size_t dataSize, int size);

    ~Font();

    void glyphMetrics(unsigned short glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const;

    void glyphMinX(unsigned short glyph, int *minX) const;
    void glyphMaxX(unsigned short glyph, int *maxX) const;
    void glyphMinY(unsigned short glyph, int *minY) const;
    void glyphMaxY(unsigned short glyph, int *maxY) const;
    void glyphAdvance(unsigned short glyph, int *advance) const;

    [[nodiscard]] int ascent() const;
    [[nodiscard]] int descent() const;
    [[nodiscard]] int lineSkip() const;

private:
    TTF_Font *m_font {nullptr};
};

}

#endif // __FONT_H__
