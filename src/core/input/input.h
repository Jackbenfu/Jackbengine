//
//  input.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 20/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __INPUT_H__
#define __INPUT_H__

#include "keyboardKey.h"
#include "mouseButton.h"
#include "core/math/vector2d.h"

NS_BEGIN_JKB

class Input
{
public:
    virtual ~Input();

    virtual void update(float delta) = 0;

    virtual bool init() = 0;

    virtual bool keyDown(KeyboardKey key) = 0;
    virtual bool keyUp(KeyboardKey key) = 0;
    virtual bool keyPress(KeyboardKey key) = 0;
    virtual int getKey(KeyboardKey key) const = 0;

    virtual bool mouseDown(MouseButton button) = 0;
    virtual bool mouseUp(MouseButton button) = 0;
    virtual bool mouseClick(MouseButton button) = 0;
    virtual bool mouseMove() = 0;
    virtual int getButton(MouseButton button) const = 0;
    virtual const Vec2i& getMousePosition() = 0;

    virtual bool quit() const = 0;

    static Input* create();

protected:
    Input();
};

NS_END_JKB

#endif // __INPUT_H__
