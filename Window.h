//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_WINDOW_H
#define CATERPILLARS_WINDOW_H

#include <SDL2/SDL_render.h>
#include "Game.h"

class Window {
private:
    int width, height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Color clearColor;

public:
    Window(const char *title, int x, int y, int width, int height, Uint32 flags);

    int getWidth() const;
    int getHeight() const;
    SDL_Renderer* getRenderer();
    void draw(Game* game);
    void clear();
    void resize();
    int setFullscreen(Uint32 flags);

    ~Window();
};

#endif //CATERPILLARS_WINDOW_H
