//
// Created by Paragoumba on 19/04/19.
//

#include "Caterpillar.h"
#include "Properties.h"
#include "Bullet.h"
#include "Utils.h"

int Caterpillar::aimingCircleRadius = 30;
std::vector<std::string> Caterpillar::textures(
        {TextureHandler::CATERPILLAR0_TEXTURE,
         TextureHandler::CATERPILLAR1_TEXTURE,
         TextureHandler::CATERPILLAR2_TEXTURE});

Caterpillar::Caterpillar(int life) : Caterpillar(0, 0, life) {}

Caterpillar::Caterpillar(int x, int y) : Caterpillar(x, y, 100) {}

Caterpillar::Caterpillar(int x, int y, int life) : life(life) {

    box.x = x;
    box.y = y;

    TextureHandler::initTexture(textures[0]);
    SDL_QueryTexture(TextureHandler::getTexture(textures[0]), nullptr, nullptr, &box.w, &box.h);

}

void Caterpillar::draw(SDL_Renderer* renderer) const {

    // Caterpillar's texture
    SDL_RenderCopyEx(renderer, TextureHandler::getTexture(textures[actualTexture]), nullptr, &box, 0, nullptr, looksRight ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

    // Life counter
    // ♥
    std::string text = std::to_string(life);
    SDL_Rect textRect;
    SDL_Color textColor = {229, 107, 104};
    SDL_Texture* texture = SDL_CreateTextureFromSurface(
            Properties::window->getRenderer(),
            TTF_RenderUTF8_Blended(
                    Properties::font,
                    text.c_str(),
                    textColor));

    TTF_SizeUTF8(Properties::font, text.c_str(), &textRect.w, &textRect.h);

    textRect.x = (int) round(box.x + (box.w - textRect.w) / 2.f);
    textRect.y = (int) round(box.y - 1.5f * textRect.h);

    SDL_RenderCopy(Properties::window->getRenderer(), texture, nullptr, &textRect);

    // Aiming point
    SDL_Rect aimingPoint;
    aimingPoint.w = aimingPoint.h = 4;
    float x, y;

    getAimingPosition(x, y);

    aimingPoint.x = (int) round(box.x + (float) box.w / 2 + x);
    aimingPoint.y = (int) round(box.y + 15 + y);

    SDL_SetRenderDrawColor(renderer, 0, 85, 255, 255);
    SDL_RenderFillRect(renderer, &aimingPoint);

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

void Caterpillar::fire() {

    auto *bullet = new Bullet();

    float x, y;

    getAimingPosition(x, y);

    bullet->setPos((int) round(box.x + (float) box.w / 2 + x), (int) round(box.y + 15 + y));
    bullet->addVelocity(x, y * 2);
    Properties::game->addEntity(bullet);

    lastFire = Utils::getTimestamp();

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

int Caterpillar::getLife() const {

    return life;

}
