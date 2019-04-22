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
    float aimingAngle = 90;
    int aimingCircleRadius = 30;
    bool looksRight = true;
    int actualTexture = 0;
    long lastFire = 0;
public:
    Caterpillar();

    long getLastFire() const;
    void getAimingPosition(float& x, float& y) const;
    void update() override;
    void draw(SDL_Renderer* renderer) const override;
    void setLooksRight(bool looksRight);
    void addAimingAngle(float angle);
    void fire();
    void nextTexture();

    static void deleteTextures();
};


#endif //CATERPILLARS_CATERPILLAR_H
