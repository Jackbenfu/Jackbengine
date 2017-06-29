//
// tmxPropertyGroup.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/11/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxPropertyGroup.h"

TmxPropertyGroup::TmxPropertyGroup()
{
}

TmxPropertyGroup::~TmxPropertyGroup()
{
    for (auto property : m_properties)
    {
        DELETE_SAFE(property);
    }
    m_properties.clear();
}

bool TmxPropertyGroup::hasProperty(const char *name) const
{
    return nullptr != getRawProperty(name);
}

const char* TmxPropertyGroup::getProperty(const char *name) const
{
    const TmxProperty *property = getRawProperty(name);
    if (property)
    {
        return property->getValue();
    }

    return nullptr;
}

bool TmxPropertyGroup::getIntProperty(const char *name, int *value) const
{
    const TmxProperty *property = getRawProperty(name);
    if (property)
    {
        return property->getIntValue(value);
    }

    return false;
}

bool TmxPropertyGroup::getUnsignedIntProperty(const char *name, uint *value) const
{
    const TmxProperty *property = getRawProperty(name);
    if (property)
    {
        return property->getUnsignedIntValue(value);
    }

    return false;
}

bool TmxPropertyGroup::getBoolProperty(const char *name, bool *value) const
{
    const TmxProperty *property = getRawProperty(name);
    if (property)
    {
        return property->getBoolValue(value);
    }

    return false;
}

bool TmxPropertyGroup::getDoubleProperty(const char *name, double *value) const
{
    const TmxProperty *property = getRawProperty(name);
    if (property)
    {
        return property->getDoubleValue(value);
    }

    return false;
}

void TmxPropertyGroup::dump() const
{
    printf("[tmxPropertyGroup][properties]\n");
    for (auto property : m_properties)
    {
        if (property)
        {
            property->dump();
        }
    }
}

const TmxProperty* TmxPropertyGroup::getRawProperty(const char *name) const
{
    vector<TmxProperty*>::const_iterator it = m_properties.begin();
    while (m_properties.end() != it)
    {
        TmxProperty *property = *it;
        if (property && !strcmp(property->getName(), name))
        {
            return property;
        }

        ++it;
    }

    return nullptr;
}

bool TmxPropertyGroup::load(const TiXmlElement *element)
{
    const TiXmlNode *node = element->FirstChild();
    while (node)
    {
        if (!strcmp("property", node->Value()))
        {
            TmxProperty *property = new TmxProperty();
            property->load(node->ToElement());
            m_properties.push_back(property);
        }

        node = node->NextSibling();
    }

    return true;
}
