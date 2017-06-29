//
// tmxObject.h
// jackbengine
//
// Created by Damien Bendejacq on 29/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_OBJECT_H__
#define __TMX_OBJECT_H__

#include "tinyxml/tinyxml.h"
#include "tmxPropertyGroup.h"

NS_BEGIN_JKB

class TmxObject
{
    friend class TmxObjectGroup;

public:
    ~TmxObject();

    const char* getName() const;
    int getGid() const;
    bool hasGid() const;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    const char* getType() const;

    bool hasProperty(const char *name) const;
    const TmxPropertyGroup* getProperties() const;

    void dump() const;

private:
    TmxObject();

    const char* m_name = nullptr;
    const char *m_type = nullptr;
    int m_gid = 0;
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;

    TmxPropertyGroup *m_properties = nullptr;

    bool load(const TiXmlElement *element);
};

NS_END_JKB

#endif // __TMX_OBJECT_H__
