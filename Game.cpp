//
// Created by Paragoumba on 19/04/19.
//

#include "Game.h"

void Game::update() {

    for (auto& entity : entities)
        entity.update();

}

void Game::draw(){

    SDL_RenderClear(Game::renderer);

    for (auto& entity : entities)
        entity.draw();

    SDL_RenderPresent(Game::renderer);

}