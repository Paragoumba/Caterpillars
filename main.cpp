//
// Created by Paragoumba on 4/19/19.
//

#include <SDL2/SDL.h>
#include <iostream>
#include <thread>
#include "Caterpillar.h"
#include "Game.h"

int Caterpillar::numTextures;
SDL_Texture** Caterpillar::textures;

Game* game;

int main(){

    game = new Game();

    Game::WIDTH = 1500;
    Game::HEIGHT = 844;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {

        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
        return 1;

    }

    SDL_Window* win = SDL_CreateWindow("Caterpillars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::WIDTH, Game::HEIGHT, SDL_WINDOW_SHOWN);

    if (win == nullptr){

        std::cout << "Error when opening window" << std::endl;
        return 1;

    }

    Game::renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    auto* caterpillar = new Caterpillar();

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    SDL_RenderClear(Game::renderer);
    SDL_RenderPresent(Game::renderer);

    int i = 0;

    bool running = true;
    SDL_Event event;

    while (running){

        if (i >= 62){

            i = 0;
            caterpillar->nextTexture();

        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        while (SDL_PollEvent(&event)) {

            switch (event.type) {

                case SDL_QUIT:

                    running = false;
                    break;

                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_z) caterpillar->addAimingAngle(10);
                    if (event.key.keysym.sym == SDLK_q) {

                        caterpillar->setLooksRight(false);
                        caterpillar->move(-5, 0);

                    }
                    if (event.key.keysym.sym == SDLK_s) caterpillar->addAimingAngle(-10);
                    if (event.key.keysym.sym == SDLK_d){

                        caterpillar->setLooksRight(true);
                        caterpillar->move(5, 0);

                    }
                    if (event.key.keysym.sym == SDLK_RETURN) caterpillar->addVelocity(0, -30);
                    if (event.key.keysym.sym == SDLK_SPACE) caterpillar->fire();

                    break;

                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {

                        running = false;
                        continue;

                    }

                    break;

                default:
                    break;

            }
        }

        update();
        draw();

        ++i;

    }

    delete game;

    return EXIT_SUCCESS;

}