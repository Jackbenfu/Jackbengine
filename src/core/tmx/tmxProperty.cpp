//
//  tmxProperty.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/11/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxProperty.h"

TmxProperty::TmxProperty()
{
}

TmxProperty::~TmxProperty()
{
}

const char* TmxProperty::getName() const
{
    return m_element->Attribute("name");
}

const char* TmxProperty::getValue() const
{
    return m_element->Attribute("value");
}

bool TmxProperty::getIntValue(int *value) const
{
    return 0 == m_element->QueryIntAttribute("value", value);
}

bool TmxProperty::getUnsignedIntValue(uint *value) const
{
    return 0 == m_element->QueryUnsignedAttribute("value", value);
}

bool TmxProperty::getBoolValue(bool *value) const
{
    return 0 == m_element->QueryBoolAttribute("value", value);
}

bool TmxProperty::getDoubleValue(double *value) const
{
    return 0 == m_element->QueryDoubleAttribute("value", value);
}

void TmxProperty::dump() const
{
    printf("[tmxProperty][name] %s\n", getName());
    printf("[tmxProperty][value] %s\n", getValue());
}

bool TmxProperty::load(const TiXmlElement *element)
{
    m_element = element;

    return true;
}
