//
// tmxImage.hpp
// jackbengine
//
// Created by Damien Bendejacq on 28/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_IMAGE_H__
#define __TMX_IMAGE_H__

#include "common.hpp"
#include "tinyxml/tinyxml.h"

namespace Jackbengine {

class TmxImage
{
    friend class TmxTileset;

public:
    ~TmxImage();

    const char* getSource() const;
    int getWidth() const;
    int getHeight() const;

    void dump() const;

private:
    TmxImage();

    const char *m_source = nullptr;
    int m_width = 0;
    int m_height = 0;

    bool load(const TiXmlElement *element);
};

} // namespace Jackbengine

#endif // __TMX_IMAGE_H__
