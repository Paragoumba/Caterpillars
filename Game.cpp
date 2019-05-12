//
// Created by Paragoumba on 19/04/19.
//

#include "Game.h"
#include "Properties.h"

void Game::update() {

    for (auto& entity : entities) {

        entity->mulVelocityY(0.9f);
        entity->move(0, 10);
        entity->update();

    }

    for (auto& entity : entitiesToDelete) {

        entities.erase(entity->getIterator());
        delete entity;

    }

    entitiesToDelete.clear();

}

void Game::draw(SDL_Renderer* renderer){

    for (auto& entity : entities)
        entity->draw(renderer);

}

void Game::addEntity(Entity* entity) {

    entity->setIterator(entities.insert(entity).first);

}

void Game::removeEntity(Entity* entity) {

    entitiesToDelete.insert(entity);

}

const std::set<Entity*>& Game::getEntities() {

    return entities;

}

Game::~Game() {

    for (auto& entity : entities)
        delete entity;

}
