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

#include "core/event/eventManager.h"
#include "core/time/timer.h"
#include "core/input/input.h"
#include "core/render/cursor/cursor.h"
#include "core/render/window/window.h"
#include "core/render/renderer/renderer.h"

namespace Jackbengine {

namespace details {
class ApplicationWrapper;
}

class Application
{
    friend class details::ApplicationWrapper;

public:
    Application() = delete;
    explicit Application(ApplicationConfig &config);
    virtual ~Application();

protected:
    virtual void frame(float delta) = 0;

private:
    [[nodiscard]] bool running() const;
    void frame();
    void userFrame(float delta);

    void onEvent(Event &e);
    bool onApplicationClosedEvent(const ApplicationClosedEvent &e);

    std::unique_ptr<Timer> m_timer;
    std::unique_ptr<Cursor> m_cursor;
    std::unique_ptr<Input> m_input;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<details::EventManager> m_eventManager;

    bool m_running {true};
};

}

#endif // __APPLICATION_H__
