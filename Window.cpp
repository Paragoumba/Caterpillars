//
// Created by Paragoumba on 19/04/19.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Window.h"
#include "Properties.h"

Window::Window(const std::string& title, int x, int y, int width, int height, Uint32 flags) : width(width), height(height) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {

        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
        exit(1);

    }

    if (TTF_Init() != 0) {

        std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
        exit(1);

    }

    Properties::font = TTF_OpenFont("../res/NotoSans-Bold.ttf", 12);

    if(!Properties::font) printf("TTF_OpenFont: %s\n", TTF_GetError());

    window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

    if (window == nullptr){

        std::cout << "Error when opening window" << std::endl;
        exit(1);

    }

    this->title = title;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    clearColor.r = clearColor.g = clearColor.b = 0;
    clearColor.a = 255;
    
    clear();
    SDL_RenderPresent(renderer);

}

void Window::draw(Game* game) {

    clear();
    game->draw(renderer);
    SDL_RenderPresent(renderer);

}

void Window::resize() {

    SDL_GL_GetDrawableSize(window, &this->width, &this->height);

}

int Window::getWidth() const {

    return width;

}

int Window::getHeight() const {

    return height;

}

SDL_Renderer *Window::getRenderer() const {

    return renderer;

}

bool Window::isFullscreen() const {

    return fullscreen;

}

void Window::clear() {
    
    SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    SDL_RenderClear(renderer);
    
}

int Window::setFullscreen(Uint32 flags) {

    int errorCode = SDL_SetWindowFullscreen(window, flags);
    fullscreen = !errorCode && flags;

    return errorCode;

}

void Window::setTitle(const std::string& title) {

    SDL_SetWindowTitle(window, title.c_str());
    this->title = title;

}

Window::~Window() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();

}
