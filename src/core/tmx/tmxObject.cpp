//
// tmxObject.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxObject.hpp"

using namespace Jackbengine;

TmxObject::TmxObject() = default;

TmxObject::~TmxObject()
{
    DELETE_SAFE(m_properties);
}

const char* TmxObject::getName() const
{
    return m_name;
}

int TmxObject::getGid() const
{
    return m_gid;
}

bool TmxObject::hasGid() const
{
    return m_gid > 0;
}

int TmxObject::getX() const
{
    return m_x;
}

int TmxObject::getY() const
{
    return m_y;
}

int TmxObject::getWidth() const
{
    return m_width;
}

int TmxObject::getHeight() const
{
    return m_height;
}

const char* TmxObject::getType() const
{
    return m_type;
}

bool TmxObject::hasProperty(const char *name) const
{
    if (nullptr == m_properties)
    {
        return false;
    }

    return m_properties->hasProperty(name);
}

const TmxPropertyGroup* TmxObject::getProperties() const
{
    return m_properties;
}

void TmxObject::dump() const
{
    printf("[tmxObject][name] %s\n", getName());
    printf("[tmxObject][type] %s\n", getType());
    printf("[tmxObject][gid] %i\n", getGid());
    printf("[tmxObject][x] %i\n", getX());
    printf("[tmxObject][y] %i\n", getY());
    printf("[tmxObject][width] %i\n", getWidth());
    printf("[tmxObject][height] %i\n", getHeight());
    if (m_properties)
    {
        m_properties->dump();
    }
}

bool TmxObject::load(const TiXmlElement *element)
{
    m_name = element->Attribute("name");
    m_type = element->Attribute("type");
    element->Attribute("gid", &m_gid);
    element->Attribute("x", &m_x);
    element->Attribute("y", &m_y);
    element->Attribute("width", &m_width);
    element->Attribute("height", &m_height);

    const TiXmlNode *node = element->FirstChild();
    while (node)
    {
        if (!strcmp("properties", node->Value()))
        {
            m_properties = new TmxPropertyGroup();
            m_properties->load(node->ToElement());
        }

        node = node->NextSibling();
    }

    return true;
}
