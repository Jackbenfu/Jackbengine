//
//  tmxMap.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 26/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_MAP_H__
#define __TMX_MAP_H__

#include <vector>
#include "tinyxml/tinyxml.h"
#include "tmxTileset.h"
#include "tmxLayer.h"
#include "tmxObjectGroup.h"
#include "tmxPropertyGroup.h"

NS_BEGIN_JKB

class TmxMap
{
public:
    TmxMap();
    ~TmxMap();

    bool load(const char *file);

    int getWidth() const;
    int getHeight() const;
    int getTileWidth() const;
    int getTileHeight() const;

    const TmxTileset* getTileset() const;

    const TmxLayer* getLayer(uint index) const;
    const TmxLayer* getLayer(const char *name) const;
    int getLayerCount() const;

    const TmxObjectGroup* getObjectGroup(uint index) const;
    const TmxObjectGroup* getObjectGroup(const char *name) const;
    int getObjectGroupCount() const;

    const TmxPropertyGroup* getProperties() const;

    int getErrorCode() const;
    const char *getErrorDescription() const;

    void dump();

private:
    int m_width = 0;
    int m_height = 0;
    int m_tileWidth = 0;
    int m_tileHeight = 0;

    TiXmlDocument *m_doc = nullptr;

    TmxTileset *m_tileset = nullptr;
    vector<TmxLayer*> m_layers;
    vector<TmxObjectGroup*> m_objectGroups;
    TmxPropertyGroup *m_properties = nullptr;
};

NS_END_JKB

#endif // __TMX_MAP_H__
