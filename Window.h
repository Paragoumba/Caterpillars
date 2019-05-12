//
// Created by Paragoumba on 19/04/19.
//

#ifndef CATERPILLARS_WINDOW_H
#define CATERPILLARS_WINDOW_H

#include "Game.h"

class Window {
private:
    SDL_Window* window;
    std::string title;
    int width, height;
    bool fullscreen = false;
    SDL_Renderer* renderer;
    SDL_Color clearColor{};

public:
    Window(const std::string& title, int x, int y, int width, int height, Uint32 flags);

    int getWidth() const;
    int getHeight() const;
    SDL_Renderer* getRenderer() const;
    bool isFullscreen() const;
    void draw(Game* game);
    void clear();
    void resize();
    int setFullscreen(Uint32 flags);
    void setTitle(const std::string& title);

    ~Window();
};

#endif //CATERPILLARS_WINDOW_H
