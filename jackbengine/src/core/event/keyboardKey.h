//
// keyboardKey.h
// jackbengine
//
// Created by Damien Bendejacq on 10/06/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __KEYBOARD_KEY_H__
#define __KEYBOARD_KEY_H__

namespace Jackbengine {

enum class KeyboardKey
{
    Unknown = 0,

    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8,
    I = 9,
    J = 10,
    K = 11,
    L = 12,
    M = 13,
    N = 14,
    O = 15,
    P = 16,
    Q = 17,
    R = 18,
    S = 19,
    T = 20,
    U = 21,
    V = 22,
    W = 23,
    X = 24,
    Y = 25,
    Z = 26,

    DIGIT_1 = 27,
    DIGIT_2 = 28,
    DIGIT_3 = 29,
    DIGIT_4 = 30,
    DIGIT_5 = 31,
    DIGIT_6 = 32,
    DIGIT_7 = 33,
    DIGIT_8 = 34,
    DIGIT_9 = 35,
    DIGIT_0 = 36,

    Return = 37,
    Escape = 38,
    Backspace = 39,
    Tab = 40,
    Space = 41,

    F1 = 42,
    F2 = 43,
    F3 = 44,
    F4 = 45,
    F5 = 46,
    F6 = 47,
    F7 = 48,
    F8 = 49,
    F9 = 50,
    F10 = 51,
    F11 = 52,
    F12 = 53,

    Right = 54,
    Left = 55,
    Down = 56,
    Up = 57,

    KeyboardKeyCount = 64,
};

}

#endif // __KEYBOARD_KEY_H__
