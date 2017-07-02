//
// tmxLayer.hpp
// jackbengine
//
// Created by Damien Bendejacq on 28/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_LAYER_H__
#define __TMX_LAYER_H__

#include <vector>
#include "tinyxml/tinyxml.h"
#include "tmxPropertyGroup.hpp"

namespace Jackbengine {

class TmxLayer
{
    friend class TmxMap;

public:
    ~TmxLayer();

    const char* getName() const;
    int getWidth() const;
    int getHeight() const;

    int getTileId(int x, int y) const;

    const int* getData() const;
    int getDataLength() const;

    const TmxPropertyGroup* getProperties() const;

    void dump() const;

private:
    TmxLayer();

    const char *m_name = nullptr;
    int m_width = 0;
    int m_height = 0;
    int *m_data = nullptr;

    TmxPropertyGroup *m_properties = nullptr;

    bool load(const TiXmlElement *element);
};

} // namespace Jackbengine

#endif // __TMX_LAYER_H__
