//
// cursor2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "cursor2.hpp"
#include "cursor2.impl.hpp"

using namespace Jackbengine;

Cursor2::Cursor2()
    : m_impl {std::make_unique<Impl>()}
{ }

Cursor2::~Cursor2() = default;

void Cursor2::setCursor(CursorType2 cursor)
{
    m_impl->setCursor(cursor);
}

void Cursor2::showCursor(bool visible)
{
    m_impl->showCursor(visible);
}
