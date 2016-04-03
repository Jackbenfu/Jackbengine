//
//  tagComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 12/05/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "tagComponent.h"

TagComponent::TagComponent()
{
}

TagComponent::~TagComponent()
{
    free(m_tag);
}

const char* TagComponent::getTag() const
{
    return m_tag;
}

void TagComponent::setTag(const char *tag)
{
    m_tag = strdup(tag);
}
