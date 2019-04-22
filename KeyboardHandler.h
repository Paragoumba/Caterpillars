//
// Created by Paragoumba on 20/04/19.
//

#ifndef CATERPILLARS_KEYBOARDHANDLER_H
#define CATERPILLARS_KEYBOARDHANDLER_H

#include <map>
#include <SDL2/SDL_events.h>

class KeyboardHandler {
private:
    static std::map<SDL_Keycode, Uint8> keyStates;
public:
    static void handleKeyboardEvent(SDL_Event& event);
    static bool isKeyPressed(int keycode);
};

#endif //CATERPILLARS_KEYBOARDHANDLER_H
