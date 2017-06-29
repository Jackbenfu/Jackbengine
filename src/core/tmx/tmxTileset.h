//
// tmxTileset.h
// jackbengine
//
// Created by Damien Bendejacq on 26/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_TILESET_H__
#define __TMX_TILESET_H__

#include "tinyxml/tinyxml.h"
#include "tmxImage.h"
#include "tmxPropertyGroup.h"

NS_BEGIN_JKB

class TmxTileset
{
    friend class TmxMap;

public:
    ~TmxTileset();

    const char* getName() const;
    int getFirstGid() const;
    int getTileWidth() const;
    int getTileHeight() const;

    const TmxImage* getImage() const;

    const TmxPropertyGroup* getProperties() const;

    void dump() const;

private:
    TmxTileset();

    const char *m_name = nullptr;
    int m_firstGid = 1;
    int m_tileWidth = 0;
    int m_tileHeight = 0;

    TmxImage *m_image = nullptr;
    TmxPropertyGroup *m_properties = nullptr;

    bool load(const TiXmlElement *element);
};

NS_END_JKB

#endif // __TMX_TILESET_H__
