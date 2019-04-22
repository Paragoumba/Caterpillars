//
// Created by Paragoumba on 19/04/19.
//

#include "Game.h"

void Game::update() {

    for (auto& entity : entities) {

        entity->mulVelocityY(0.9f);
        entity->move(0, 10);
        entity->update();

    }
}

void Game::draw(SDL_Renderer* renderer){

    for (auto& entity : entities)
        entity->draw(renderer);

}

void Game::addEntity(Entity* entity) {

    entities.push_back(entity);

}

void Game::removeEntity(Entity* entity) {

    for (auto it = entities.begin(); it != entities.end(); ++it) {

        if ((*it) == entity){

            entities.erase(it);
            return;

        }
    }
}
