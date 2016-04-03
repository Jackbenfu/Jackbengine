//
//  renderer.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "renderer.h"
#include "rendererImpl.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

Renderer* Renderer::create()
{
    return new RendererImpl();
}
