//
// eventManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "eventManager.h"
#include "impl/eventImpl.h"

namespace Jackbengine::details {

EventManager::EventManager(std::function<void(Event &)> callback)
    : m_callback {std::move(callback)}
{
}

void EventManager::update()
{
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    SDL_Event event {};
    while (SDL_PollEvent(&event) > 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                ApplicationCloseEvent e;
                m_callback(e);
                break;
            }

            case SDL_KEYDOWN:
            {
                handleKeyDown(event.key.keysym);
                break;
            }

            case SDL_KEYUP:
            {
                handleKeyUp(event.key.keysym);
                break;
            }

            case SDL_MOUSEMOTION:
            {
                MouseMotionEvent e {mouseX, mouseY};
                m_callback(e);
                break;
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                handleMouseDown(event.button, SDL_BUTTON_LEFT, mouseX, mouseY);
                handleMouseDown(event.button, SDL_BUTTON_MIDDLE, mouseX, mouseY);
                handleMouseDown(event.button, SDL_BUTTON_RIGHT, mouseX, mouseY);
                break;
            }

            case SDL_MOUSEBUTTONUP:
            {

                handleMouseUp(event.button, SDL_BUTTON_LEFT, mouseX, mouseY);
                handleMouseUp(event.button, SDL_BUTTON_MIDDLE, mouseX, mouseY);
                handleMouseUp(event.button, SDL_BUTTON_RIGHT, mouseX, mouseY);
                break;
            }

            default:
                break;
        }
    }

    handleMouseDownRepeat(SDL_BUTTON_LEFT, mouseX, mouseY);
    handleMouseDownRepeat(SDL_BUTTON_MIDDLE, mouseX, mouseY);
    handleMouseDownRepeat(SDL_BUTTON_RIGHT, mouseX, mouseY);
}

void EventManager::handleKeyDown(const SDL_Keysym &keysym)
{
    const auto scanCode = keysym.scancode;
    const auto physicalKey = getPhysicalKey(scanCode);
    const auto virtualKey = getVirtualKey(keysym.sym);

    m_keysDown[scanCode] = true;

    KeyDownEvent e {physicalKey, virtualKey, m_keysDownRepeat[scanCode]};
    m_callback(e);

    ++m_keysDownRepeat[scanCode];
}

void EventManager::handleKeyUp(const SDL_Keysym &keysym)
{
    const auto scanCode = keysym.scancode;
    const auto physicalKey = getPhysicalKey(scanCode);
    const auto virtualKey = getVirtualKey(keysym.sym);

    if (m_keysDown[scanCode])
    {
        KeyPressEvent e {physicalKey, virtualKey};
        m_callback(e);
    }

    m_keysDown[scanCode] = false;
    m_keysDownRepeat[scanCode] = 0;

    KeyUpEvent e {physicalKey, virtualKey};
    m_callback(e);
}

void EventManager::handleMouseDown(const SDL_MouseButtonEvent &event, int button, int mouseX, int mouseY)
{
    if (event.button != button)
    {
        return;
    }

    m_mouseDown[button] = true;

    MouseDownEvent e {mouseX, mouseY, getButton(button), 0};
    m_callback(e);
}

void EventManager::handleMouseDownRepeat(int button, int mouseX, int mouseY)
{
    if (m_mouseDown[button])
    {
        auto repeat = ++m_mouseDownRepeat[button];

        MouseDownEvent e {mouseX, mouseY, getButton(button), repeat};
        m_callback(e);
    }
}

void EventManager::handleMouseUp(const SDL_MouseButtonEvent &event, int button, int mouseX, int mouseY)
{
    if (event.button != button)
    {
        return;
    }

    const auto b = getButton(button);

    if (m_mouseDown[button])
    {
        MouseClickEvent e {mouseX, mouseY, b};
        m_callback(e);
    }

    m_mouseDown[button] = false;
    m_mouseDownRepeat[button] = 0;

    MouseUpEvent e {mouseX, mouseY, b};
    m_callback(e);
}

KeyboardKey EventManager::getPhysicalKey(int scanCode) const
{
    switch (scanCode)
    {
        case SDL_SCANCODE_A:
            return KeyboardKey::A;
        case SDL_SCANCODE_B:
            return KeyboardKey::B;
        case SDL_SCANCODE_C:
            return KeyboardKey::C;
        case SDL_SCANCODE_D:
            return KeyboardKey::D;
        case SDL_SCANCODE_E:
            return KeyboardKey::E;
        case SDL_SCANCODE_F:
            return KeyboardKey::F;
        case SDL_SCANCODE_G:
            return KeyboardKey::G;
        case SDL_SCANCODE_H:
            return KeyboardKey::H;
        case SDL_SCANCODE_I:
            return KeyboardKey::I;
        case SDL_SCANCODE_J:
            return KeyboardKey::J;
        case SDL_SCANCODE_K:
            return KeyboardKey::K;
        case SDL_SCANCODE_L:
            return KeyboardKey::L;
        case SDL_SCANCODE_M:
            return KeyboardKey::M;
        case SDL_SCANCODE_N:
            return KeyboardKey::N;
        case SDL_SCANCODE_O:
            return KeyboardKey::O;
        case SDL_SCANCODE_P:
            return KeyboardKey::P;
        case SDL_SCANCODE_Q:
            return KeyboardKey::Q;
        case SDL_SCANCODE_R:
            return KeyboardKey::R;
        case SDL_SCANCODE_S:
            return KeyboardKey::S;
        case SDL_SCANCODE_T:
            return KeyboardKey::T;
        case SDL_SCANCODE_U:
            return KeyboardKey::U;
        case SDL_SCANCODE_V:
            return KeyboardKey::V;
        case SDL_SCANCODE_W:
            return KeyboardKey::W;
        case SDL_SCANCODE_X:
            return KeyboardKey::X;
        case SDL_SCANCODE_Y:
            return KeyboardKey::Y;
        case SDL_SCANCODE_Z:
            return KeyboardKey::Z;

        case SDL_SCANCODE_1:
            return KeyboardKey::DIGIT_1;
        case SDL_SCANCODE_2:
            return KeyboardKey::DIGIT_2;
        case SDL_SCANCODE_3:
            return KeyboardKey::DIGIT_3;
        case SDL_SCANCODE_4:
            return KeyboardKey::DIGIT_4;
        case SDL_SCANCODE_5:
            return KeyboardKey::DIGIT_5;
        case SDL_SCANCODE_6:
            return KeyboardKey::DIGIT_6;
        case SDL_SCANCODE_7:
            return KeyboardKey::DIGIT_7;
        case SDL_SCANCODE_8:
            return KeyboardKey::DIGIT_8;
        case SDL_SCANCODE_9:
            return KeyboardKey::DIGIT_9;
        case SDL_SCANCODE_0:
            return KeyboardKey::DIGIT_0;

        case SDL_SCANCODE_RETURN:
            return KeyboardKey::Return;
        case SDL_SCANCODE_ESCAPE:
            return KeyboardKey::Escape;
        case SDL_SCANCODE_BACKSPACE:
            return KeyboardKey::Backspace;
        case SDL_SCANCODE_TAB:
            return KeyboardKey::Tab;
        case SDL_SCANCODE_SPACE:
            return KeyboardKey::Space;

        case SDL_SCANCODE_F1:
            return KeyboardKey::F1;
        case SDL_SCANCODE_F2:
            return KeyboardKey::F2;
        case SDL_SCANCODE_F3:
            return KeyboardKey::F3;
        case SDL_SCANCODE_F4:
            return KeyboardKey::F4;
        case SDL_SCANCODE_F5:
            return KeyboardKey::F5;
        case SDL_SCANCODE_F6:
            return KeyboardKey::F6;
        case SDL_SCANCODE_F7:
            return KeyboardKey::F7;
        case SDL_SCANCODE_F8:
            return KeyboardKey::F8;
        case SDL_SCANCODE_F9:
            return KeyboardKey::F9;
        case SDL_SCANCODE_F10:
            return KeyboardKey::F10;
        case SDL_SCANCODE_F11:
            return KeyboardKey::F11;
        case SDL_SCANCODE_F12:
            return KeyboardKey::F12;

        case SDL_SCANCODE_DOWN:
            return KeyboardKey::Down;
        case SDL_SCANCODE_RIGHT:
            return KeyboardKey::Right;
        case SDL_SCANCODE_LEFT:
            return KeyboardKey::Left;
        case SDL_SCANCODE_UP:
            return KeyboardKey::Up;

        default:
            return KeyboardKey::Unknown;
    }
}

KeyboardKey EventManager::getVirtualKey(int sym) const
{
    switch (sym)
    {
        case SDLK_a:
            return KeyboardKey::A;
        case SDLK_b:
            return KeyboardKey::B;
        case SDLK_c:
            return KeyboardKey::C;
        case SDLK_d:
            return KeyboardKey::D;
        case SDLK_e:
            return KeyboardKey::E;
        case SDLK_f:
            return KeyboardKey::F;
        case SDLK_g:
            return KeyboardKey::G;
        case SDLK_h:
            return KeyboardKey::H;
        case SDLK_i:
            return KeyboardKey::I;
        case SDLK_j:
            return KeyboardKey::J;
        case SDLK_k:
            return KeyboardKey::K;
        case SDLK_l:
            return KeyboardKey::L;
        case SDLK_m:
            return KeyboardKey::M;
        case SDLK_n:
            return KeyboardKey::N;
        case SDLK_o:
            return KeyboardKey::O;
        case SDLK_p:
            return KeyboardKey::P;
        case SDLK_q:
            return KeyboardKey::Q;
        case SDLK_r:
            return KeyboardKey::R;
        case SDLK_s:
            return KeyboardKey::S;
        case SDLK_t:
            return KeyboardKey::T;
        case SDLK_u:
            return KeyboardKey::U;
        case SDLK_v:
            return KeyboardKey::V;
        case SDLK_w:
            return KeyboardKey::W;
        case SDLK_x:
            return KeyboardKey::X;
        case SDLK_y:
            return KeyboardKey::Y;
        case SDLK_z:
            return KeyboardKey::Z;

        case SDLK_1:
            return KeyboardKey::DIGIT_1;
        case SDLK_2:
            return KeyboardKey::DIGIT_2;
        case SDLK_3:
            return KeyboardKey::DIGIT_3;
        case SDLK_4:
            return KeyboardKey::DIGIT_4;
        case SDLK_5:
            return KeyboardKey::DIGIT_5;
        case SDLK_6:
            return KeyboardKey::DIGIT_6;
        case SDLK_7:
            return KeyboardKey::DIGIT_7;
        case SDLK_8:
            return KeyboardKey::DIGIT_8;
        case SDLK_9:
            return KeyboardKey::DIGIT_9;
        case SDLK_0:
            return KeyboardKey::DIGIT_0;

        case SDLK_RETURN:
            return KeyboardKey::Return;
        case SDLK_ESCAPE:
            return KeyboardKey::Escape;
        case SDLK_BACKSPACE:
            return KeyboardKey::Backspace;
        case SDLK_TAB:
            return KeyboardKey::Tab;
        case SDLK_SPACE:
            return KeyboardKey::Space;

        case SDLK_F1:
            return KeyboardKey::F1;
        case SDLK_F2:
            return KeyboardKey::F2;
        case SDLK_F3:
            return KeyboardKey::F3;
        case SDLK_F4:
            return KeyboardKey::F4;
        case SDLK_F5:
            return KeyboardKey::F5;
        case SDLK_F6:
            return KeyboardKey::F6;
        case SDLK_F7:
            return KeyboardKey::F7;
        case SDLK_F8:
            return KeyboardKey::F8;
        case SDLK_F9:
            return KeyboardKey::F9;
        case SDLK_F10:
            return KeyboardKey::F10;
        case SDLK_F11:
            return KeyboardKey::F11;
        case SDLK_F12:
            return KeyboardKey::F12;

        case SDLK_DOWN:
            return KeyboardKey::Down;
        case SDLK_RIGHT:
            return KeyboardKey::Right;
        case SDLK_LEFT:
            return KeyboardKey::Left;
        case SDLK_UP:
            return KeyboardKey::Up;

        default:
            return KeyboardKey::Unknown;
    }
}

MouseButton EventManager::getButton(int button) const
{
    switch (button)
    {
        case SDL_BUTTON_LEFT:
            return MouseButton::Left;
        case SDL_BUTTON_MIDDLE:
            return MouseButton::Middle;
        case SDL_BUTTON_RIGHT:
            return MouseButton::Right;

        default:
            return MouseButton::Unknown;
    }
}

}
