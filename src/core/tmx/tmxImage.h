//
//  tmxImage.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 28/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_IMAGE_H__
#define __TMX_IMAGE_H__

#include "common.h"
#include "tinyxml/tinyxml.h"

NS_BEGIN_JKB

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

NS_END_JKB

#endif // __TMX_IMAGE_H__
