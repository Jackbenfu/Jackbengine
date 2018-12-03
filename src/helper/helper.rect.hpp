//
// helper.rect.hpp
// jackbengine
//
// Created by Damien Bendejacq on 04/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __HELPER_RECT_H__
#define __HELPER_RECT_H__

#include "core/math/rect.hpp"

namespace Jackbengine {

#define RECTF(x, y, w, h)    Jackbengine::Rectf(x, y, w, h)
#define RECTI(x, y, w, h)    Jackbengine::Recti(x, y, w, h)

#define RECT_SCREEN          RECTF(0, 0, window().width(), window().height())

}

#endif // __HELPER_RECT_H__
