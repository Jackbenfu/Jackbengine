//
// application2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_2_H__
#define __APPLICATION_2_H__

#include "applicationConfig.hpp"
#include "abstract/abstractApplication.hpp"

#include "core/input/input2.hpp"
#include "core/render/cursor/cursor2.hpp"
#include "core/render/renderer/renderer2.hpp"
#include "core/render/window/window2.hpp"
#include "core/time/timer2.hpp"

namespace Jackbengine {

class Application2 : public AbstractApplication
{
    DISALLOW_COPY_AND_MOVE(Application2)

public:
    explicit Application2(ApplicationConfig& config);
    virtual ~Application2() = default;

    bool running() const;
    void loop();

private:
    Timer2 m_timer;
    Cursor2 m_cursor;
    Input2 m_input;
    Window2 m_window;
    Renderer2 m_renderer;

    bool m_running {true};
};

} // namespace Jackbengine

#endif // __APPLICATION_2_H__
