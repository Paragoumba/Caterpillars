//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_BULLET_H
#define CATERPILLARS_BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet();

    void update() override;
    void draw(SDL_Renderer* renderer) const override;
};


#endif //CATERPILLARS_BULLET_H
