//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_GAME_H
#define CATERPILLARS_GAME_H

#include <SDL2/SDL_render.h>
#include <vector>
#include "Entity.h"

class Game {
private:
    std::vector<Entity*> entities;
public:
    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    void update();
    void draw(SDL_Renderer* renderer);
};


#endif //CATERPILLARS_GAME_H
