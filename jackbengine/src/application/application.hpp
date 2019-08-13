//
// application.hpp
// jackbengine
//
// Created by Damien Bendejacq on 10/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "applicationConfig.hpp"
#include "abstract/abstractApplication.hpp"

#include "core/input/input.hpp"
#include "core/render/cursor/cursor.hpp"
#include "core/render/renderer/renderer.hpp"
#include "core/render/window/window.hpp"
#include "core/time/timer.hpp"

namespace Jackbengine {

class Application : public AbstractApplication
{
public:
    Application() = delete;
    explicit Application(ApplicationConfig &config);
    ~Application() override = default;

    bool running() const;
    void loop();

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
