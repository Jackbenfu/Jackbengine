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
    virtual void frame(float delta) = 0;

    Timer2& timer() const;
    Cursor2& cursor() const;
    Input2& input() const;
    Window2& window() const;
    Renderer2& renderer() const;

private:
    mutable Timer2 m_timer;
    mutable Cursor2 m_cursor;
    mutable Input2 m_input;
    mutable Window2 m_window;
    mutable Renderer2 m_renderer;

    bool m_running {true};
};

} // namespace Jackbengine

#endif // __APPLICATION_2_H__
