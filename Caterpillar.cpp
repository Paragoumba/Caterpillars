//
// Created by Paragoumba on 19/04/19.
//

#include <string>
#include <time.h>
#include <iostream>
#include "Caterpillar.h"
#include "Properties.h"
#include "Bullet.h"

Caterpillar::Caterpillar() {

    numTextures = 3;
    textures = new SDL_Texture*[numTextures]{nullptr};

    for (int i = 0; i < numTextures; ++i){

        std::string path = "/home/paragoumba/Documents/Dev/C++/Code/Games/Caterpillars/res/caterpillar";
        path.append(std::to_string(i)).append(".bmp");
        textures[i] = SDL_CreateTextureFromSurface(Properties::window->getRenderer(), SDL_LoadBMP(path.c_str()));

    }

    SDL_QueryTexture(textures[0], nullptr, nullptr, &box.w, &box.h);
    box.x = 0;
    box.y = 0;

}

void Caterpillar::draw(SDL_Renderer* renderer) const {

    SDL_Rect rect;
    rect.w = rect.h = 4;
    float x, y;

    getAimingPosition(x, y);

    rect.x = (int) round(box.x + (float) box.w / 2 + x);
    rect.y = (int) round(box.y + 15 + y);

    SDL_RenderCopyEx(renderer, textures[actualTexture], nullptr, &box, 0, nullptr, looksRight ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    SDL_SetRenderDrawColor(renderer, 0, 85, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

}

void Caterpillar::update() {

    box.x += (int) round(velX);
    box.y += (int) round(velY);

    if (box.x < 0) box.x = 0;
    if (box.y < 0) box.y = 0;

    int windowWidth = Properties::window->getWidth();
    int windowHeight = Properties::window->getHeight();

    if (box.x >= windowWidth - box.w) box.x = windowWidth - box.w;
    if (box.y >= windowHeight - box.h) box.y = windowHeight - box.h;

}

void Caterpillar::setLooksRight(bool looksRight) {

    this->looksRight = looksRight;

}

void Caterpillar::addAimingAngle(float angle) {

    aimingAngle += angle;

    if (aimingAngle < 0) aimingAngle = 0;
    else if (aimingAngle > 180) aimingAngle = 180;

}

void Caterpillar::nextTexture() {

    actualTexture++;

    if (actualTexture >= numTextures) actualTexture = 0;

}

void Caterpillar::fire() {

    auto *bullet = new Bullet();

    float x, y;

    getAimingPosition(x, y);

    bullet->setPos((int) round(box.x + (float) box.w / 2 + x), (int) round(box.y + 15 + y));
    bullet->addVelocity(x, y);
    Properties::game->addEntity(bullet);

    lastFire = time(nullptr);

}

void Caterpillar::deleteTextures() {

    for (int i = 0; i < numTextures; ++i)
        SDL_DestroyTexture(textures[i]);

    delete textures;

}

long Caterpillar::getLastFire() const {

    return lastFire;

}

void Caterpillar::getAimingPosition(float &x, float& y) const {

    x = (looksRight ? -1 : 1) *                 // Changes circle's side according to caterpillar's orientation
        aimingCircleRadius *
        cos((aimingAngle + 90) * M_PI / 180);   // Component x of the point of the aiming circle
                                                // towards which caterpillar aims
    y = aimingCircleRadius *
        sin((aimingAngle + 90) * M_PI / 180);   // Component y of the point of the aiming circle
                                                // towards which caterpillar aims

}
