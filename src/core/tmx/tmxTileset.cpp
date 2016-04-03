//
//  tmxTileset.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 26/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxTileset.h"

TmxTileset::TmxTileset()
{
}

TmxTileset::~TmxTileset()
{
    DELETE_SAFE(m_properties);
    DELETE_SAFE(m_image);
}

const char* TmxTileset::getName() const
{
    return m_name;
}

int TmxTileset::getFirstGid() const
{
    return m_firstGid;
}

int TmxTileset::getTileWidth() const
{
    return m_tileWidth;
}

int TmxTileset::getTileHeight() const
{
    return m_tileHeight;
}

const TmxImage* TmxTileset::getImage() const
{
    return m_image;
}

const TmxPropertyGroup* TmxTileset::getProperties() const
{
    return m_properties;
}

void TmxTileset::dump() const
{
    printf("[tmxTileset][name] %s\n", getName());
    printf("[tmxTileset][firstGid] %i\n", getFirstGid());
    printf("[tmxTileset][tileWidth] %i\n", getTileWidth());
    printf("[tmxTileset][tileHeight] %i\n", getTileHeight());
    if (m_image)
    {
        m_image->dump();
    }
    if (m_properties)
    {
        m_properties->dump();
    }
}

bool TmxTileset::load(const TiXmlElement *element)
{
    m_name = element->Attribute("name");
    element->Attribute("firstgid", &m_firstGid);
    element->Attribute("tilewidth", &m_tileWidth);
    element->Attribute("tileheight", &m_tileHeight);

    const TiXmlNode *node = element->FirstChild();
    while (node)
    {
        if (!strcmp("image", node->Value()))
        {
            m_image = new TmxImage();
            m_image->load(node->ToElement());
        }
        else if (!strcmp("properties", node->Value()))
        {
            m_properties = new TmxPropertyGroup();
            m_properties->load(node->ToElement());
        }

        node = node->NextSibling();
    }

    return true;
}
