//
// Created by Paragoumba on 20/04/19.
//

#include "KeyboardHandler.h"

void KeyboardHandler::handleKeyboardEvent(SDL_Event &event) {

    keyStates[event.key.keysym.sym] = event.key.state;

}

bool KeyboardHandler::isKeyPressed(int keycode) {

    return keyStates[keycode] == SDL_PRESSED;

}