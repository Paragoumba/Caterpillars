//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_GAME_H
#define CATERPILLARS_GAME_H

#include <set>
#include "Entity.h"

class Game {
private:
    std::set<Entity*> entities;
    std::set<Entity*> entitiesToDelete;
public:
    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    void update();
    void draw(SDL_Renderer* renderer);
    const std::set<Entity*>& getEntities();

    ~Game();
};


#endif //CATERPILLARS_GAME_H
