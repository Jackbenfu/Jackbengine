//
// zIndexComponent.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "zIndexComponent.hpp"

namespace Jackbengine {

ZIndexComponent::ZIndexComponent(uint index)
    : m_index {index}
{
}

uint ZIndexComponent::index() const
{
    return m_index;
}

void ZIndexComponent::setIndex(uint index)
{
    m_index = index;
}

}
