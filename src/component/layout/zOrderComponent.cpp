//
// zOrderComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 26/09/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#include "zOrderComponent.h"

ZOrderComponent::ZOrderComponent()
{
}

ZOrderComponent::~ZOrderComponent()
{
}

int ZOrderComponent::getIndex() const
{
    return m_index;
}

void ZOrderComponent::setIndex(int index)
{
    m_index = index;
}