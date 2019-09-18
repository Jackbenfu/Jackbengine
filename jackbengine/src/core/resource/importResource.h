//
// importResource.h
// jackbengine
//
// Created by Damien Bendejacq on 22/05/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __IMPORT_RESOURCE_H__
#define __IMPORT_RESOURCE_H__

namespace Jackbengine {

#define IMPORT_BINARY_RESOURCE(name)    extern "C" char name[];         \
                                        extern "C" size_t name##_size;

#define IMPORT_TEXT_RESOURCE(name)      extern "C" char name[];

}

#endif // __IMPORT_RESOURCE_H__
