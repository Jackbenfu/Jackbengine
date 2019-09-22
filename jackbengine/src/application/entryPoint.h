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

extern std::unique_ptr<Application> createApplication(bool fullscreen);

namespace details {

class ApplicationWrapper
{
public:
    explicit ApplicationWrapper(Application *application)
        : m_application {application}
    {}

    [[nodiscard]] inline bool running() const
    {
        return m_application->running();
    }

    inline void update()
    {
        m_application->update();
    }

private:
    Application *m_application;
};

}

}

#endif // __ENTRY_POINT_H__
