//
//  tmxMap.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 26/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxMap.h"

TmxMap::TmxMap()
{
    m_doc = new TiXmlDocument();
}

TmxMap::~TmxMap()
{
    DELETE_SAFE(m_properties);
    DELETE_SAFE(m_tileset);

    for (auto objectGroup : m_objectGroups)
    {
        DELETE_SAFE(objectGroup);
    }
    m_objectGroups.clear();

    for (auto layer : m_layers)
    {
        DELETE_SAFE(layer);
    }
    m_layers.clear();

    DELETE_SAFE(m_doc);
}

bool TmxMap::loadFromFile(const char *file)
{
    char filePath[255];

#ifdef __APPLE__

    // BEGIN extract
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFStringRef resourceString = CFStringCreateWithCString(nullptr, file, kCFStringEncodingASCII);
    CFURLRef resourceUrl = CFBundleCopyResourceURL(mainBundle, resourceString, nullptr, nullptr);
    CFURLGetFileSystemRepresentation(resourceUrl, true, (UInt8*)filePath, 4096);
    CFRelease(resourceUrl);
    CFRelease(resourceString);
    CFBundleUnloadExecutable(mainBundle);
    // END extract

#else

    strcpy(filePath, file);

#endif

    if (!m_doc->LoadFile(filePath))
    {
        printf("%s: %s (%i)\n", filePath, m_doc->ErrorDesc(), m_doc->ErrorId());
        return false;
    }

    return loadContents();
}

bool TmxMap::loadFromMemory(const void *data, size_t dataSize)
{
    if (!m_doc->Parse((char*)data))
    {
        printf("%s (%i)\n", m_doc->ErrorDesc(), m_doc->ErrorId());
        return false;
    }

    return loadContents();
}

int TmxMap::getWidth() const
{
    return m_width;
}

int TmxMap::getHeight() const
{
    return m_height;
}

int TmxMap::getTileWidth() const
{
    return m_tileWidth;
}

int TmxMap::getTileHeight() const
{
    return m_tileHeight;
}

const TmxTileset* TmxMap::getTileset() const
{
    return m_tileset;
}

const TmxLayer* TmxMap::getLayer(uint index) const
{
    if (m_layers.size() > index)
    {
        return m_layers[index];
    }

    return nullptr;
}

const TmxLayer* TmxMap::getLayer(const char *name) const
{
    for (auto layer : m_layers)
    {
        if (!strcmp(name, layer->getName()))
        {
            return layer;
        }
    }

    return nullptr;
}

int TmxMap::getLayerCount() const
{
    return (int)m_layers.size();
}

const TmxObjectGroup* TmxMap::getObjectGroup(uint index) const
{
    if (m_objectGroups.size() > index)
    {
        return m_objectGroups[index];
    }

    return nullptr;
}

const TmxObjectGroup* TmxMap::getObjectGroup(const char *name) const
{
    for (auto objectGroup : m_objectGroups)
    {
        if (!strcmp(name, objectGroup->getName()))
        {
            return objectGroup;
        }
    }

    return nullptr;
}

int TmxMap::getObjectGroupCount() const
{
    return (int)m_objectGroups.size();
}

const TmxPropertyGroup* TmxMap::getProperties() const
{
    return m_properties;
}

int TmxMap::getErrorCode() const
{
    return m_doc->ErrorId();
}

const char *TmxMap::getErrorDescription() const
{
    return m_doc->ErrorDesc();
}

void TmxMap::dump()
{
    printf("[tmxMap][width] %i\n", getWidth());
    printf("[tmxMap][height] %i\n", getHeight());
    printf("[tmxMap][tileWidth] %i\n", getTileWidth());
    printf("[tmxMap][tileHeight] %i\n", getTileHeight());
    if (m_properties)
    {
        m_properties->dump();
    }
    if (m_tileset)
    {
        m_tileset->dump();
    }
    for (auto layer : m_layers)
    {
        if (layer)
        {
            printf("----------------\n");
            layer->dump();
        }
    }
    for (auto objectGroup : m_objectGroups)
    {
        if (objectGroup)
        {
            printf("----------------\n");
            objectGroup->dump();
        }
    }
}

bool TmxMap::loadContents()
{
    const TiXmlNode *node = m_doc->FirstChild("map");
    const TiXmlElement *map = node->ToElement();

    map->Attribute("width", &m_width);
    map->Attribute("height", &m_height);
    map->Attribute("tilewidth", &m_tileWidth);
    map->Attribute("tileheight", &m_tileHeight);

    node = map->FirstChild();
    while (node)
    {
        if (!strcmp("tileset", node->Value()))
        {
            m_tileset = new TmxTileset();
            m_tileset->load(node->ToElement());
        }
        else if (!strcmp("layer", node->Value()))
        {
            TmxLayer *layer = new TmxLayer();
            layer->load(node->ToElement());
            m_layers.push_back(layer);
        }
        else if (!strcmp("objectgroup", node->Value()))
        {
            TmxObjectGroup *objectGroup = new TmxObjectGroup();
            objectGroup->load(node->ToElement());
            m_objectGroups.push_back(objectGroup);
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
