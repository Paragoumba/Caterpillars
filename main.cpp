//
// Created by Paragoumba on 4/19/19.
//

#include <SDL2/SDL.h>
#include <iostream>
#include <thread>
#include "Caterpillar.h"
#include "Properties.h"
#include "KeyboardHandler.h"

int Caterpillar::numTextures;
SDL_Texture** Caterpillar::textures;
Game* Properties::game;
Window* Properties::window;
std::map<SDL_Keycode, Uint8> KeyboardHandler::keyStates;

int main(){

    Properties::game = new Game();
    Properties::window = new Window(
                    "Caterpillars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    1500, 844, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    Properties::window->setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);

    auto* caterpillar = new Caterpillar();

    caterpillar->setPos(
            (Properties::window->getWidth() + caterpillar->getWidth()) / 2,
            Properties::window->getHeight());

    Properties::game->addEntity(caterpillar);

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

                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {

                        Properties::window->resize();

                    }
                    break;

                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    KeyboardHandler::handleKeyboardEvent(event);
                    break;

                default:
                    break;

            }
        }

        if (KeyboardHandler::isKeyPressed(SDLK_z)) caterpillar->addAimingAngle(5);
        if (KeyboardHandler::isKeyPressed(SDLK_q)) {

            caterpillar->setLooksRight(false);
            caterpillar->move(-5, 0);

        }
        if (KeyboardHandler::isKeyPressed(SDLK_s)) caterpillar->addAimingAngle(-5);
        if (KeyboardHandler::isKeyPressed(SDLK_d)){

            caterpillar->setLooksRight(true);
            caterpillar->move(5, 0);

        }
        if (KeyboardHandler::isKeyPressed(SDLK_RETURN) && caterpillar->isOnGround()) caterpillar->addVelocity(0, -40);
        if (KeyboardHandler::isKeyPressed(SDLK_SPACE) /*&&
        ztime(nullptr) - caterpillar->getLastFire() > 1*/) caterpillar->fire();
        if (KeyboardHandler::isKeyPressed(SDLK_ESCAPE)) {

            running = false;
            continue;

        }

        Properties::game->update();
        Properties::window->draw(Properties::game);

        ++i;

    }

    Caterpillar::deleteTextures();
    delete Properties::game;
    delete Properties::window;

    SDL_Quit();

    return EXIT_SUCCESS;

}