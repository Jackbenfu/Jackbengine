//
// entryPoint.h
// jackbengine
//
// Created by Damien Bendejacq on 21/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __ENTRY_POINT_H__
#define __ENTRY_POINT_H__

#include "application.h"

namespace Jackbengine {

extern std::unique_ptr<Application> CreateApplication(bool fullscreen);

}

#endif // __ENTRY_POINT_H__
