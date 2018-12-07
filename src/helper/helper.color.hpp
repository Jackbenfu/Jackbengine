//
// helper.color.hpp
// jackbengine
//
// Created by Damien Bendejacq on 04/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_COLOR_H__
#define __HELPER_COLOR_H__

#include "core/render/color.hpp"

namespace Jackbengine {

#define COLOR_RGB(r, g, b)      Jackbengine::Color(r, g, b)
#define COLOR_RGBA(r, g, b, a)  Jackbengine::Color(r, g, b, a)

#define COLOR_BLACK             COLOR_RGB(0, 0, 0)
#define COLOR_WHITE             COLOR_RGB(255, 255, 255)
#define COLOR_RED               COLOR_RGB(255, 0, 0)
#define COLOR_GREEN             COLOR_RGB(0, 255, 0)
#define COLOR_BLUE              COLOR_RGB(0, 0, 255)

}

#endif // __HELPER_COLOR_H__
