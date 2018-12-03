//
// helper.color.hpp
// jackbengine
//
// Created by Damien Bendejacq on 04/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_COLOR_H__
#define __HELPER_COLOR_H__

#include "core/render/color32.hpp"

namespace Jackbengine {

#define COLOR(r, g, b)      Jackbengine::Color32(r, g, b)
#define COLOR32(r, g, b, a) Jackbengine::Color32(r, g, b, a)

#define COLOR_RED           COLOR(255, 0, 0)
#define COLOR_GREEN         COLOR(0, 255, 0)
#define COLOR_BLUE          COLOR(0, 0, 255)

}

#endif // __HELPER_COLOR_H__
