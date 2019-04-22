//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_ENTITY_H
#define CATERPILLARS_ENTITY_H

#include <SDL2/SDL_render.h>

class Entity {
protected:
    SDL_Rect box;
    float velX = 0, velY = 0;
public:
    void move(int x, int y);
    virtual void update() = 0;
    virtual void draw(SDL_Renderer* render) const = 0;
    void setPos(int x, int y);
    void addVelocity(float velX, float velY);
    void mulVelocityY(float m);
    int getWidth() const;
    int getHeight() const;
    bool isOnGround();
};

#endif //CATERPILLARS_ENTITY_H
