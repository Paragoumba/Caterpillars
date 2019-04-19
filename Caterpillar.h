//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_CATERPILLAR_H
#define CATERPILLARS_CATERPILLAR_H

#include <SDL2/SDL_render.h>
#include "Entity.h"

class Caterpillar : public Entity {
private:
    static int numTextures;
    static SDL_Texture** textures;
    SDL_Rect box;
    float velX = 0, velY = 0;
    float aimingAngle = 90;
    bool looksRight = true;
    int actualTexture = 0;
public:
    Caterpillar();

    void draw() const;
    void move(int x, int y);
    void addVelocity(float velX, float velY);
    void setLooksRight(bool looksRight);
    void addAimingAngle(float angle);
    void fire();
    void nextTexture();
    void update() override;

    static void deleteTextures();
};


#endif //CATERPILLARS_CATERPILLAR_H
