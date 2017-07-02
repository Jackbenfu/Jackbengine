//
// tmxProperty.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/11/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_PROPERTY_H__
#define __TMX_PROPERTY_H__

#include <string>
#include "common.hpp"
#include "tinyxml/tinyxml.h"

namespace Jackbengine {

class TmxProperty
{
    friend class TmxPropertyGroup;

public:
    ~TmxProperty();

    const char* getName() const;
    const char* getValue() const;

    bool getIntValue(int *value) const;
    bool getUnsignedIntValue(uint *value) const;
    bool getBoolValue(bool *value) const;
    bool getDoubleValue(double *value) const;

    void dump() const;

private:
    TmxProperty();

    const TiXmlElement *m_element = nullptr;
    const char *m_name = nullptr;
    const char *m_value = nullptr;

    bool load(const TiXmlElement *element);
};

} // namespace Jackbengine

#endif // __TMX_PROPERTY_H__
