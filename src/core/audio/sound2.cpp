//
// sound2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "sound2.hpp"
#include "sound2.impl.hpp"

using namespace Jackbengine;

Sound2::Sound2(const std::string& file)
    : m_impl {std::make_unique<Impl>(file)}
{ }

Sound2::Sound2(const void *data, size_t dataSize)
    : m_impl {std::make_unique<Impl>(data, dataSize)}
{ }

Sound2::~Sound2() = default;

void Sound2::play(bool loop) const
{
    m_impl->play(loop);
}
