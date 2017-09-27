//
// input2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "input2.hpp"
#include "input2.impl.hpp"

using namespace Jackbengine;

Input2::Input2()
    : m_impl {std::make_unique<Impl>()}
{ }

Input2::~Input2() = default;

void Input2::update()
{
    m_impl->update();
}

bool Input2::keyDown(KeyboardKey key) const
{
    return m_impl->keyDown(key);
}

bool Input2::keyUp(KeyboardKey key) const
{
    return m_impl->keyUp(key);
}

bool Input2::keyPress(KeyboardKey key) const
{
    return m_impl->keyPress(key);
}

bool Input2::mouseDown(MouseButton button) const
{
    return m_impl->mouseDown(button);
}

bool Input2::mouseUp(MouseButton button) const
{
    return m_impl->mouseUp(button);
}

bool Input2::mouseClick(MouseButton button) const
{
    return m_impl->mouseClick(button);
}

bool Input2::mouseMove() const
{
    return m_impl->mouseMove();
}

const Jackbengine::Vector2d<int>& Input2::mousePosition() const
{
    return m_impl->mousePosition();
}

bool Input2::quit() const
{
    return m_impl->quit();
}
