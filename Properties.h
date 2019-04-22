//
// Created by Paragoumba on 20/04/19.
//

#ifndef CATERPILLARS_PROPERTIES_H
#define CATERPILLARS_PROPERTIES_H

#include "Game.h"
#include "Window.h"

class Properties {
public:
    Properties() = delete;
    static Game* game;
    static Window* window;
};

#endif //CATERPILLARS_PROPERTIES_H
