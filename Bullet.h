//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_BULLET_H
#define CATERPILLARS_BULLET_H

#include "Entity.h"
#include "TextureHandler.h"

class Bullet : public Entity {
private:
    static std::vector<std::string> textures;
    static int explosionRadius;
public:
    Bullet();

    void update() override;
    void draw(SDL_Renderer* renderer) const override;
    void explode();
};

#endif //CATERPILLARS_BULLET_H
