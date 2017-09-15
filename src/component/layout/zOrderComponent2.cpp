//
// zOrderComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "zOrderComponent2.hpp"

using namespace Jackbengine;

ZOrderComponent2::ZOrderComponent2(int index)
    : m_index {index}
{
    // Nothing
}

int ZOrderComponent2::index() const
{
    return m_index;
}

void ZOrderComponent2::setIndex(int index)
{
    m_index = index;
}
