//
// application.h
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "applicationConfig.h"
#include "abstract/abstractApplication.h"

#include "core/input/input.h"
#include "core/render/cursor/cursor.h"
#include "core/render/renderer/renderer.h"
#include "core/render/window/window.h"
#include "core/time/timer.h"

namespace Jackbengine {

class Application : public AbstractApplication
{
public:
    Application() = delete;
    explicit Application(ApplicationConfig &config);
    ~Application() override = default;

    bool running() const;
    void frame();

    void userFrame(float delta);
    virtual void frame(float delta) = 0;

    inline const Timer &timer() const
    {
        return *m_timer;
    }

    inline const Cursor &cursor() const
    {
        return *m_cursor;
    }

    inline const Input &input() const
    {
        return *m_input;
    }

    inline const Window &window() const
    {
        return *m_window;
    }

    inline const Renderer &renderer() const
    {
        return *m_renderer;
    }

    void exit();

private:
    std::unique_ptr<Timer> m_timer;
    std::unique_ptr<Cursor> m_cursor;
    std::unique_ptr<Input> m_input;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;

    bool m_running {true};
};

}

#endif // __APPLICATION_H__
