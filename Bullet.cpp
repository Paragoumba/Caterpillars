//
// Created by Paragoumba on 19/04/19.
//

#include "Bullet.h"
#include "Properties.h"

Bullet::Bullet() {

    box.x = box.y = 0;
    box.w = box.h = 4;

}

void Bullet::update() {

    box.x += (int) round(velX);
    box.y += (int) round(velY);

    if (box.x < 0) box.x = 0;
    if (box.y < 0) box.y = 0;

    int windowWidth = Properties::window->getWidth();
    int windowHeight = Properties::window->getHeight();

    if (isOnGround()){

        Properties::game->removeEntity(this);
        delete this;
        return;

    }

    // Check if the bullet is about to exit the window
    if (box.x >= windowWidth - box.w) box.x = windowWidth - box.w;
    if (box.y >= windowHeight - box.h) box.y = windowHeight - box.h;

}

void Bullet::draw(SDL_Renderer* renderer) const {

    //SDL_RenderCopy(renderer, texture, nullptr, &box);
    SDL_SetRenderDrawColor(renderer, 0, 255, 85, 255);
    SDL_RenderFillRect(renderer, &box);

}
