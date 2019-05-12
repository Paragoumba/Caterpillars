//
// Created by Paragoumba on 20/04/19.
//

#ifndef CATERPILLARS_PROPERTIES_H
#define CATERPILLARS_PROPERTIES_H

#include <SDL2/SDL_ttf.h>
#include "Game.h"
#include "Window.h"

class Properties {
public:
    Properties() = delete;

    static std::string programName;
    static std::string version;
    static Game* game;
    static Window* window;
    static TTF_Font* font;
};

#endif //CATERPILLARS_PROPERTIES_H
