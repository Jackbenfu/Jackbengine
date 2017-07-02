//
// tmxLayer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 28/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxLayer.hpp"

using namespace Jackbengine;

TmxLayer::TmxLayer() = default;

TmxLayer::~TmxLayer()
{
    DELETE_SAFE(m_properties);
    DELETE_SAFE_ARRAY(m_data);
}

const char* TmxLayer::getName() const
{
    return m_name;
}

int TmxLayer::getWidth() const
{
    return m_width;
}

int TmxLayer::getHeight() const
{
    return m_height;
}

int TmxLayer::getTileId(int x, int y) const
{
    int pos = y * m_width + x;
    if (m_width * m_height > pos)
    {
        return m_data[pos];
    }

    return -1;
}

const int* TmxLayer::getData() const
{
    return m_data;
}

int TmxLayer::getDataLength() const
{
    return m_width * m_height;
}

const TmxPropertyGroup* TmxLayer::getProperties() const
{
    return m_properties;
}

bool TmxLayer::load(const TiXmlElement *element)
{
    m_name = element->Attribute("name");
    element->Attribute("width", &m_width);
    element->Attribute("height", &m_height);

    const TiXmlNode *node = element->FirstChild();
    while (node)
    {
        if (!strcmp("data", node->Value()))
        {
            const TiXmlElement *data = element->FirstChildElement("data");
            const char *encoding = data->Attribute("encoding");

            if (!strcmp("csv", encoding))
            {
                const char *delimiters = ",";

                char *csv = strdup(data->GetText());
                char *token = strtok(csv, delimiters);

                m_data = new int[m_width * m_height];
                int i = 0;

                while (token)
                {
                    int tileId;
                    sscanf(token, "%i", &tileId);
                    m_data[i++] = tileId;
                    
                    token = strtok(nullptr, delimiters);
                }

                free(csv);
            }
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

void TmxLayer::dump() const
{
    printf("[tmxLayer][name] %s\n", getName());
    printf("[tmxLayer][width] %i\n", getWidth());
    printf("[tmxLayer][height] %i\n", getHeight());
    printf("[tmxLayer][data]\n");
    for (int y = 0; y < getHeight(); ++y)
    {
        for (int x = 0; x < getWidth(); ++x)
        {
            if (getWidth() - 1 == x && getHeight() - 1 == y)
            {
                printf("%i", getTileId(x, y));
            }
            else
            {
                printf("%i,", getTileId(x, y));
            }
        }
        printf("\n");
    }
    if (m_properties)
    {
        m_properties->dump();
    }
}
