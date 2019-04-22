//
// Created by Paragoumba on 20/04/19.
//

#include "Entity.h"
#include "Properties.h"

void Entity::move(int x, int y) {

    box.x += x;
    box.y += y;

}

int Entity::getWidth() const {

    return box.w;

}

int Entity::getHeight() const {

    return box.h;

}

void Entity::setPos(int x, int y) {

    box.x = x;
    box.y = y;

}

void Entity::addVelocity(float velX, float velY) {

    this->velX += velX;
    this->velY += velY;

}

bool Entity::isOnGround() {

    return box.y >= Properties::window->getHeight() - box.h;

}

void Entity::mulVelocityY(float m) {

    velY *= m;

}
