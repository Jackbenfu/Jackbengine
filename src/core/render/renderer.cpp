//
// renderer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "renderer.hpp"
#include "rendererImpl.hpp"

using namespace Jackbengine;

Renderer::Renderer() = default;

Renderer::~Renderer() = default;

Renderer* Renderer::create()
{
    return new RendererImpl();
}
