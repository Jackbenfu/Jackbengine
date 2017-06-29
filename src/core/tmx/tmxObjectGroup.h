//
// tmxObjectGroup.h
// jackbengine
//
// Created by Damien Bendejacq on 29/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_OBJECTGROUP_H__
#define __TMX_OBJECTGROUP_H__

#include <vector>
#include "tinyxml/tinyxml.h"
#include "tmxObject.h"
#include "tmxPropertyGroup.h"

NS_BEGIN_JKB

class TmxObjectGroup
{
    friend class TmxMap;

public:
    ~TmxObjectGroup();

    const char* getName() const;

    const TmxObject* getObject(int index) const;
    const TmxObject* getObject(const char *name) const;
    int getObjectCount() const;

    int getOriginX() const;
    int getOriginY() const;

    bool hasProperty(const char *name) const;
    const TmxPropertyGroup* getProperties() const;

    void dump() const;

private:
    TmxObjectGroup();

    const char* m_name = nullptr;
    vector<TmxObject*> m_objects;
    TmxPropertyGroup *m_properties = nullptr;

    bool load(const TiXmlElement *element);
};

NS_END_JKB

#endif // __TMX_OBJECTGROUP_H__
