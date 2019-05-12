//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_CATERPILLAR_H
#define CATERPILLARS_CATERPILLAR_H

#include <SDL2/SDL_render.h>
#include <vector>
#include "Entity.h"
#include "TextureHandler.h"

class Caterpillar : public Entity {
private:
    static std::vector<std::string> textures;
    int life;
    float aimingAngle = 90;
    static int aimingCircleRadius;
    bool looksRight = true;
    long lastFire = 0;
public:
    explicit Caterpillar(int life);
    explicit Caterpillar(int x = 0, int y = 0);
    explicit Caterpillar(int x, int y, int life);

    int getLife() const;
    long getLastFire() const;
    void getAimingPosition(float& x, float& y) const;
    void update() override;
    void draw(SDL_Renderer* renderer) const override;
    void setLooksRight(bool looksRight);
    void addAimingAngle(float angle);
    void fire();
};

#endif //CATERPILLARS_CATERPILLAR_H
