//
// inputImpl.h
// jackbengine
//
// Created by Damien Bendejacq on 20/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __INPUT_IMPL_H__
#define __INPUT_IMPL_H__

#include "input.h"

NS_BEGIN_JKB

class InputImpl : public Input
{
    friend class Input;

public:
    ~InputImpl();

    void update(float delta) override;

    bool init() override;

    bool keyDown(KeyboardKey key) override;
    bool keyUp(KeyboardKey key) override;
    bool keyPress(KeyboardKey key) override;
    int getKey(KeyboardKey key) const override;

    bool mouseDown(MouseButton button) override;
    bool mouseUp(MouseButton button) override;
    bool mouseClick(MouseButton button) override;
    bool mouseMove() override;
    int getButton(MouseButton button) const override;
    const Vec2i& getMousePosition() override;

    bool quit() const override;

private:
    InputImpl();

    bool *m_keyboardKeysDown;
    bool *m_keyboardKeysPress;

    bool *m_mouseButtonsDown;
    bool *m_mouseButtonsClick;
    Vec2i m_mousePos;
    bool m_mouseMove = false;

    uint m_maxMouseButtons;

    bool m_quit = false;
};

NS_END_JKB

#endif // __INPUT_IMPL_H__
