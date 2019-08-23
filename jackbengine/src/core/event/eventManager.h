//
// eventManager.h
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "core/event/event.h"
#include "keyboardKey.h"
#include "mouseButton.h"

namespace Jackbengine::details {

class EventManager
{
    friend class Application;

public:
    explicit EventManager(std::function<void(Event &)> callback);
    ~EventManager() = default;

    void update();

private:
    [[nodiscard]] KeyboardKey getPhysicalKey(SDL_Keysym keysym) const;
    [[nodiscard]] KeyboardKey getVirtualKey(SDL_Keysym keysym) const;
    [[nodiscard]] MouseButton getButton(int button) const;

    void handleMouseDown(const SDL_MouseButtonEvent& event, int button, int mouseX, int mouseY);
    void handleMouseUp(const SDL_MouseButtonEvent& event, int button, int mouseX, int mouseY);
    void handleMouseDownRepeat(int button, int mouseX, int mouseY);

    std::function<void(Event &)> m_callback;

    std::vector<bool> m_keyboardKeysDown = std::vector<bool>(SDL_NUM_SCANCODES, false);
    std::vector<bool> m_keyboardKeysPress = std::vector<bool>(SDL_NUM_SCANCODES, false);

    const unsigned int MaxMouseButtons {4};
    std::vector<bool> m_mouseButtonsDown = std::vector<bool>(MaxMouseButtons, false);
    std::vector<bool> m_mouseButtonsDownOnCurrentFrame = std::vector<bool>(MaxMouseButtons, false);
};

}

#endif // __EVENT_MANAGER_H__
