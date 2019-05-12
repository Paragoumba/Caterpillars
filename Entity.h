//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_ENTITY_H
#define CATERPILLARS_ENTITY_H

#include <SDL2/SDL_render.h>
#include <set>
#include <vector>

class Entity {
protected:
    static std::vector<std::string> textures;
    std::set<Entity*>::iterator it;
    SDL_Rect box{};
    float velX = 0, velY = 0;
    int actualTexture = 0;
public:
    explicit Entity(int x = 0, int y = 0);

    int getWidth() const;
    int getHeight() const;
    std::set<Entity*>::iterator getIterator();
    bool isOnGround() const;

    void move(int x, int y);
    virtual void update() = 0;
    virtual void draw(SDL_Renderer* renderer) const = 0;

    virtual void nextTexture();
    void setPos(int x, int y);
    void addVelocity(float velX, float velY);
    void mulVelocityY(float m);
    void setIterator(std::set<Entity*>::iterator it);
    virtual ~Entity() = default;
};

#endif //CATERPILLARS_ENTITY_H