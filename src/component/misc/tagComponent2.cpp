//
// tagComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "tagComponent2.hpp"

using namespace Jackbengine;

TagComponent2::TagComponent2(const std::string& tag)
    : m_value(tag)
{ }

const std::string& TagComponent2::get() const
{
    return m_value.get();
}

void TagComponent2::set(const std::string& tag)
{
    m_value.set(tag);
}
