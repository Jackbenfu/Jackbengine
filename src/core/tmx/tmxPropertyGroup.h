//
//  tmxPropertyGroup.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/11/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_PROPERTYGROUP_H__
#define __TMX_PROPERTYGROUP_H__

#include <vector>
#include "common.h"
#include "tinyxml/tinyxml.h"
#include "tmxProperty.h"

NS_BEGIN_JKB
NS_STD

class TmxPropertyGroup
{
    friend class TmxMap;
    friend class TmxTileset;
    friend class TmxObjectGroup;
    friend class TmxObject;
    friend class TmxLayer;

public:
    ~TmxPropertyGroup();

    const char* getProperty(const char *name) const;
    bool getIntProperty(const char *name, int *value) const;
    bool getUnsignedIntProperty(const char *name, uint *value) const;
    bool getBoolProperty(const char *name, bool *value) const;
    bool getDoubleProperty(const char *name, double *value) const;

    void dump() const;

private:
    TmxPropertyGroup();

    vector<TmxProperty*> m_properties;
    const TmxProperty *getRawProperty(const char *name) const;

    bool load(const TiXmlElement *element);
};

NS_END_JKB

#endif // __TMX_PROPERTYGROUP_H__