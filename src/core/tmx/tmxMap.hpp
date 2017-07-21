//
// tmxMap.hpp
// jackbengine
//
// Created by Damien Bendejacq on 26/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_MAP_H__
#define __TMX_MAP_H__

#include <vector>

#include "tinyxml/tinyxml.h"
#include "tmxTileset.hpp"
#include "tmxLayer.hpp"
#include "tmxObjectGroup.hpp"
#include "tmxPropertyGroup.hpp"

namespace Jackbengine {

class TmxMap
{
public:
    TmxMap();
    ~TmxMap();

    bool loadFromFile(const char *file);
    bool loadFromMemory(const unsigned char *data);

    int getWidth() const;
    int getHeight() const;
    int getTileWidth() const;
    int getTileHeight() const;

    const TmxTileset* getTileset() const;

    const TmxLayer* getLayer(int index) const;
    const TmxLayer* getLayer(const char *name) const;
    int getLayerCount() const;

    const TmxObjectGroup* getObjectGroup(int index) const;
    const TmxObjectGroup* getObjectGroup(const char *name) const;
    int getObjectGroupCount() const;

    const TmxPropertyGroup* getProperties() const;

    int getErrorCode() const;
    const char *getErrorDescription() const;

    void dump();

private:
    bool loadContents();

    int m_width = 0;
    int m_height = 0;
    int m_tileWidth = 0;
    int m_tileHeight = 0;

    TiXmlDocument *m_doc = nullptr;

    TmxTileset *m_tileset = nullptr;
    std::vector<TmxLayer*> m_layers;
    std::vector<TmxObjectGroup*> m_objectGroups;
    TmxPropertyGroup *m_properties = nullptr;
};

} // namespace Jackbengine

#endif // __TMX_MAP_H__