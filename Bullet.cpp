//
// Created by Paragoumba on 19/04/19.
//

#include <iostream>
#include "Bullet.h"
#include "Properties.h"

int Bullet::explosionRadius = 15;
std::vector<std::string> Bullet::textures({TextureHandler::BULLET_TEXTURE});

Bullet::Bullet() {

    TextureHandler::initTexture(textures[0]);
    SDL_QueryTexture(TextureHandler::getTexture(textures[0]), nullptr, nullptr, &box.w, &box.h);

}

void Bullet::update() {

    box.x += (int) round(velX);
    box.y += (int) round(velY);

    if (box.x < 0) box.x = 0;
    if (box.y < 0) box.y = 0;

    int windowWidth = Properties::window->getWidth();
    int windowHeight = Properties::window->getHeight();

    if (isOnGround())
        Properties::game->removeEntity(this);

    // Check if the bullet is about to exit the window
    if (box.x >= windowWidth - box.w) box.x = windowWidth - box.w;
    if (box.y >= windowHeight - box.h) box.y = windowHeight - box.h;

}

void Bullet::draw(SDL_Renderer* renderer) const {

    SDL_Point center;

    //center.x = box.x + box.w / 2;
    //center.y = box.y + box.h / 2;
    center.x = 0;
    center.y = 0;

    std::cout << "velX:" << velX << " velY:" << velY << " -velY:" << -velY << " d:" << velX / -velY << " atan:" << atan(velX / -velY) * (180.0 / M_PI) << std::endl;

    // TODO Fix bullet orientation
    SDL_RenderCopyEx(
            renderer,
            TextureHandler::getTexture(textures[actualTexture]),
            nullptr,
            &box,
            (velY > 0 ? 90 : 0) + atan(velX / -velY) * (180.0 / M_PI),
            &center,
            SDL_FLIP_NONE);

    // Draws a filled rect
    /*SDL_Rect rect;

    rect.x = box.x;
    rect.y = box.y;
    rect.w = rect.h = 4;

    SDL_SetRenderDrawColor(renderer, 0, 255, 85, 255);
    SDL_RenderFillRect(renderer, &rect);*/

    // Draws a filled circle
    //Utils::fillCircle(renderer, box.x, box.y, 10);

}

void Bullet::explode() {

    // TODO Finish to implement bullet explosion
    const std::set<Entity*> entities = Properties::game->getEntities();

    for(Entity* entity : entities){

        float distance = 10;

    }
}
