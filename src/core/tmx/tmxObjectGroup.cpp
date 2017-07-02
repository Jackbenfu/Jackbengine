//
// tmxObjectGroup.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/10/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxObjectGroup.hpp"

using namespace Jackbengine;

TmxObjectGroup::TmxObjectGroup() = default;

TmxObjectGroup::~TmxObjectGroup()
{
    DELETE_SAFE(m_properties);

    for (auto object : m_objects)
    {
        DELETE_SAFE(object);
    }
    m_objects.clear();
}

const char* TmxObjectGroup::getName() const
{
    return m_name;
}

const TmxObject* TmxObjectGroup::getObject(int index) const
{
    if (0 <= index && static_cast<int>(m_objects.size()) > index)
    {
        return m_objects[index];
    }

    return nullptr;
}

const TmxObject* TmxObjectGroup::getObject(const char *name) const
{
    for (auto object : m_objects)
    {
        if (!strcmp(name, object->getName()))
        {
            return object;
        }
    }

    return nullptr;
}

int TmxObjectGroup::getObjectCount() const
{
    return static_cast<int>(m_objects.size());
}

int TmxObjectGroup::getOriginX() const
{
    int originX = 0;

    for (auto object : m_objects)
    {
        if (object)
        {
            int objectX = object->getX();

            originX = objectX < originX ? objectX : originX;
        }
    }

    return originX;
}

int TmxObjectGroup::getOriginY() const
{
    int originY = 0;

    for (auto object : m_objects)
    {
        if (object)
        {
            int objectY = object->getY();

            originY = objectY < originY ? objectY : originY;
        }
    }

    return originY;
}

bool TmxObjectGroup::hasProperty(const char *name) const
{
    if (nullptr == m_properties)
    {
        return false;
    }

    return m_properties->hasProperty(name);
}

const TmxPropertyGroup* TmxObjectGroup::getProperties() const
{
    return m_properties;
}

void TmxObjectGroup::dump() const
{
    printf("[tmxObjectGroup][name] %s\n", getName());
    printf("[tmxObjectGroup][objects]\n");
    for (auto object : m_objects)
    {
        if (object)
        {
            object->dump();
        }
    }
    if (m_properties)
    {
        m_properties->dump();
    }
}

bool TmxObjectGroup::load(const TiXmlElement *element)
{
    m_name = element->Attribute("name");

    const TiXmlNode *node = element->FirstChild();
    while (node)
    {
        if (!strcmp("object", node->Value()))
        {
            TmxObject *object = new TmxObject();
            object->load(node->ToElement());
            m_objects.push_back(object);
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
