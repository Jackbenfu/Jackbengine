//
// eventManager.h
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include <vector>

#include "core/event/event.h"
#include "keyboardKey.h"
#include "mouseButton.h"

struct SDL_Keysym;
typedef struct SDL_MouseButtonEvent SDL_MouseButtonEvent;

namespace Jackbengine {

class Application;

namespace details {

class EventManager
{
    friend class Jackbengine::Application;

public:
    explicit EventManager(std::function<void(Event &)> callback);
    ~EventManager() = default;

    [[nodiscard]] bool isKeyDown(KeyboardKey key) const;
    [[nodiscard]] bool isKeyUp(KeyboardKey key) const;
    [[nodiscard]] bool isKeyPressed(KeyboardKey key) const;

    [[nodiscard]] bool isMouseDown(MouseButton button) const;
    [[nodiscard]] bool isMouseUp(MouseButton button) const;
    [[nodiscard]] bool isMouseClicked(MouseButton button) const;

private:
    void update();

    void handleKeyDown(const SDL_Keysym &keysym);
    void handleKeyDownRepeat(KeyboardKey key);
    void handleKeyUp(const SDL_Keysym &keysym);

    void handleMouseDown(const SDL_MouseButtonEvent &event, int button, int mouseX, int mouseY);
    void handleMouseDownRepeat(int button, int mouseX, int mouseY);
    void handleMouseUp(const SDL_MouseButtonEvent &event, int button, int mouseX, int mouseY);

    [[nodiscard]] int getScanCode(KeyboardKey key) const;
    [[nodiscard]] KeyboardKey getPhysicalKey(int scanCode) const;
    [[nodiscard]] KeyboardKey getVirtualKey(int sym) const;
    [[nodiscard]] MouseButton getButton(int button) const;

    std::function<void(Event &)> m_callback;

    std::vector<bool> m_keyDown = std::vector<bool>((int) KeyboardKey::KeyboardKeyCount, false);
    std::vector<bool> m_keyDownOnFrame = std::vector<bool>((int) KeyboardKey::KeyboardKeyCount, false);
    std::vector<int> m_keyDownRepeat = std::vector<int>((int) KeyboardKey::KeyboardKeyCount, 0);
    std::vector<int> m_keyPress = std::vector<int>((int) KeyboardKey::KeyboardKeyCount, false);

    const unsigned int MaxMouseButtons {4};
    std::vector<bool> m_mouseDown = std::vector<bool>(MaxMouseButtons, false);
    std::vector<bool> m_mouseDownOnFrame = std::vector<bool>(MaxMouseButtons, false);
    std::vector<int> m_mouseDownRepeat = std::vector<int>(MaxMouseButtons, 0);
    std::vector<int> m_mouseClick = std::vector<int>(MaxMouseButtons, false);
};

}
}

#endif // __EVENT_MANAGER_H__
