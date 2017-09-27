//
// nameComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "nameComponent2.hpp"

using namespace Jackbengine;

NameComponent2::NameComponent2(const std::string& name)
    : m_value {name}
{ }

const std::string& NameComponent2::get() const
{
    return m_value.get();
}

void NameComponent2::set(const std::string& name)
{
    m_value.set(name);
}
