//
// debugProfileSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 23/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "debugProfileSystem.h"
#include "core/resource/importResource.h"

IMPORT_BINARY_RESOURCE(default_font)

DebugProfileSystem::DebugProfileSystem()
{
    memset(m_fpsBuf, 0, FPS_BUF_SIZE);
}

DebugProfileSystem::~DebugProfileSystem()
{
    DELETE_SAFE(m_fps);
}

void DebugProfileSystem::update(float delta)
{
    UNUSED(delta);

    if (m_showFps)
    {
        int fps = m_timer->getFps();
        if (0 == fps)
        {
            snprintf(m_fpsBuf, FPS_BUF_SIZE, "--");
        }
        else
        {
            snprintf(
                m_fpsBuf, FPS_BUF_SIZE, "%ifps",
                m_timer->getFps()
            );
        }
        m_fps->setText(m_fpsBuf);
        m_renderer->renderTexture(4, 3, m_fps->getTexture());
    }
}

void DebugProfileSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;

    m_fps = new TextComponent();
    m_fps->setFontFromMemory(m_renderer, default_font, default_font_size, 9);
}

bool DebugProfileSystem::hasRequiredComponents(Entity *entity)
{
    UNUSED(entity);

    return false;
}

void DebugProfileSystem::setTimer(Timer *timer)
{
    m_timer = timer;
}

void DebugProfileSystem::setForeground(Color color)
{
    m_fps->setForeground(color);
}

void DebugProfileSystem::showFps(bool show)
{
    m_showFps = show;
}
