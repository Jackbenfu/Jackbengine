//
// texture.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "texture.hpp"
#include "textureImpl.hpp"

using namespace Jackbengine;

Texture::Texture() = default;

Texture::~Texture() = default;

Texture* Texture::create()
{
    return new TextureImpl();
}
