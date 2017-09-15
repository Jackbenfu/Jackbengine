//
// window2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 11/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __WINDOW_2_H__
#define __WINDOW_2_H__

#include <memory>
#include <string>
#include "common.hpp"

namespace Jackbengine {

class Window2
{
    friend class Renderer2;

    DISALLOW_COPY_AND_MOVE(Window2)

public:
    Window2(const std::string& title, int width, int height, bool fullscreen);
    ~Window2();

    int width() const;
    int height() const;

private:
    void* internalObject() const;

    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __WINDOW_2_H__
