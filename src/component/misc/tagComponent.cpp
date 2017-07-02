//
// tagComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/05/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "tagComponent.hpp"
#include "platform.hpp"

using namespace Jackbengine;

TagComponent::TagComponent() = default;

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
