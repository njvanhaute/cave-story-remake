//
//  input.cpp
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/15/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "input.h"

// Input Class:
// Keeps track of the state of the keyboard.

// This function is called at the beginning of each new frame
// to reset keys that are no longer relevant.
void Input::beginNewFrame() {
    _pressedKeys.clear();
    _releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event &event) {
    _pressedKeys[event.key.keysym.scancode] = true;
    _heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event &event) {
    _releasedKeys[event.key.keysym.scancode] = true;
    _heldKeys[event.key.keysym.scancode] = false;
}

// Check if certain key was pressed
bool Input::wasKeyPressed(SDL_Scancode key) {
    return _pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
    return _releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return _heldKeys[key];
}
