//
// Created by Paragoumba on 20/04/19.
//

#include "Entity.h"
#include "Properties.h"
#include "TextureHandler.h"

std::vector<std::string> Entity::textures;

Entity::Entity(int x, int y) {

    box.x = x;
    box.y = y;

}

int Entity::getWidth() const {

    return box.w;

}

int Entity::getHeight() const {

    return box.h;

}

std::set<Entity *>::iterator Entity::getIterator() {

    return it;

}

bool Entity::isOnGround() const {

    return box.y >= Properties::window->getHeight() - box.h;

}

void Entity::move(int x, int y) {

    box.x += x;
    box.y += y;

}

void Entity::nextTexture() {

    actualTexture++;

    if (actualTexture >= textures.size()) actualTexture = 0;

}

void Entity::setPos(int x, int y) {

    box.x = x;
    box.y = y;

}

void Entity::addVelocity(float velX, float velY) {

    this->velX += velX;
    this->velY += velY;

}

void Entity::mulVelocityY(float m) {

    velY *= m;

}

void Entity::setIterator(std::set<Entity*>::iterator it) {

    this->it = it;

}
