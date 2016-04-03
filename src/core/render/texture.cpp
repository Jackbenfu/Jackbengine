//
//  texture.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 17/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "texture.h"
#include "textureImpl.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

Texture* Texture::create()
{
    return new TextureImpl();
}
