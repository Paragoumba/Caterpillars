//
// Created by Paragoumba on 19/04/19.
//

#include <math.h>
#include <iostream>
#include "Caterpillar.h"
#include "Game.h"

Caterpillar::Caterpillar() {

    numTextures = 3;
    textures = new SDL_Texture*[numTextures];

    for (int i = 0; i < numTextures; ++i){

        std::string path = "/home/paragoumba/Documents/Dev/C++/Code/Games/Caterpillars/res/caterpillar";
        path.append(std::to_string(i)).append(".bmp");
        textures[i] = SDL_CreateTextureFromSurface(Game::renderer, SDL_LoadBMP(path.c_str()));

    }

    SDL_QueryTexture(textures[0], nullptr, nullptr, &box.w, &box.h);
    box.x = (Game::WIDTH + box.w) / 2;
    box.y = (Game::HEIGHT + box.h) / 2;

}

void Caterpillar::draw() const {

    SDL_Rect rect;

    rect.h = 4;
    rect.w = 4;

    int middleX = box.w / 2;

    if (looksRight) {

        rect.x = box.x + middleX + (int) round(-30 * cos((aimingAngle + 90) * M_PI / 180));
        rect.y = box.y - (int) round(-30 * sin((aimingAngle + 90) * M_PI / 180)) + 15;

    } else {

        rect.x = box.x + middleX + (int) round(30 * cos((aimingAngle + 90) * M_PI / 180));
        rect.y = box.y + (int) round(30 * sin((aimingAngle + 90) * M_PI / 180)) + 15;

    }

    SDL_RenderCopyEx(Game::renderer, textures[actualTexture], nullptr, &box, 0, nullptr, looksRight ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    SDL_SetRenderDrawColor(Game::renderer, 0, 85, 255, 255);
    SDL_RenderFillRect(Game::renderer, &rect);
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

}

void Caterpillar::move(int x, int y) {

    box.x += x;
    box.y += y;

}

void Caterpillar::update() {

    velY *= 0.90;

    box.x += velX;
    box.y += velY;

    if (aimingAngle < 0) aimingAngle = 0;
    else if (aimingAngle > 180) aimingAngle = 180;
    if (box.x < 0) box.x = 0;
    if (box.y < 0) box.y = 0;
    if (box.x >= Game::WIDTH - box.w) box.x = Game::WIDTH - box.w;
    if (box.y >= Game::HEIGHT - box.h) box.y = Game::HEIGHT - box.h;

}

void Caterpillar::addVelocity(float velX, float velY) {

    this->velX += velX;
    this->velY += velY;

}

void Caterpillar::setLooksRight(bool looksRight) {

    this->looksRight = looksRight;

}

void Caterpillar::addAimingAngle(float angle) {

    aimingAngle += angle;

}

void Caterpillar::nextTexture() {

    actualTexture++;

    if (actualTexture >= numTextures) actualTexture = 0;

}

void Caterpillar::fire() {



}

void Caterpillar::deleteTextures() {

    for (int i = 0; i < numTextures; ++i)
        SDL_DestroyTexture(textures[i]);

    delete textures;

}
