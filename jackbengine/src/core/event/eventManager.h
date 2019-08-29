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
#include "core/sdl/sdl.h"
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
    void handleKeyDown(const SDL_Keysym &keysym);
    void handleKeyDownRepeat(KeyboardKey key);
    void handleKeyUp(const SDL_Keysym &keysym);

    void handleMouseDown(const SDL_MouseButtonEvent &event, int button, int mouseX, int mouseY);
    void handleMouseDownRepeat(int button, int mouseX, int mouseY);
    void handleMouseUp(const SDL_MouseButtonEvent &event, int button, int mouseX, int mouseY);

    [[nodiscard]] SDL_Scancode getScanCode(KeyboardKey key) const;
    [[nodiscard]] KeyboardKey getPhysicalKey(int scanCode) const;
    [[nodiscard]] KeyboardKey getVirtualKey(int sym) const;
    [[nodiscard]] MouseButton getButton(int button) const;

    std::function<void(Event &)> m_callback;

    std::vector<bool> m_keyDown = std::vector<bool>((int) KeyboardKey::KeyboardKeyCount, false);
    std::vector<bool> m_keyDownOnFrame = std::vector<bool>((int) KeyboardKey::KeyboardKeyCount, false);
    std::vector<int> m_keyDownRepeat = std::vector<int>((int) KeyboardKey::KeyboardKeyCount, 0);

    const unsigned int MaxMouseButtons {4};
    std::vector<bool> m_mouseDown = std::vector<bool>(MaxMouseButtons, false);
    std::vector<bool> m_mouseDownOnFrame = std::vector<bool>(MaxMouseButtons, false);
    std::vector<int> m_mouseDownRepeat = std::vector<int>(MaxMouseButtons, 0);
};

}

#endif // __EVENT_MANAGER_H__
