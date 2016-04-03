//
//  tmxImage.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 28/10/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "tmxImage.h"

TmxImage::TmxImage()
{
}

TmxImage::~TmxImage()
{
}

const char* TmxImage::getSource() const
{
    return m_source;
}

int TmxImage::getWidth() const
{
    return m_width;
}

int TmxImage::getHeight() const
{
    return m_height;
}

void TmxImage::dump() const
{
    printf("[tmxImage][source] %s\n", getSource());
    printf("[tmxImage][width] %i\n", getWidth());
    printf("[tmxImage][height] %i\n", getHeight());
}

bool TmxImage::load(const TiXmlElement *element)
{
    m_source = element->Attribute("source");
    element->Attribute("width", &m_width);
    element->Attribute("height", &m_height);

    return true;
}
