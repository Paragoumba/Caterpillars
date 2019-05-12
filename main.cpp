//
// Created by Paragoumba on 4/19/19.
//


#include <thread>
#include "Properties.h"
#include "Caterpillar.h"
#include "Utils.h"
#include "KeyboardHandler.h"

int main(){

    Properties::programName = "Caterpillars";
    Properties::version = "0.4.2";

    Properties::game = new Game();
    Properties::window = new Window(
                    Properties::programName + " - " + Properties::version, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    1500, 844, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    auto* caterpillar = new Caterpillar();

    caterpillar->setPos(
            0,
            Properties::window->getHeight());

    Properties::game->addEntity(caterpillar);

    long start = Utils::getTimestamp();
    int i = 0;
    bool running = true;
    SDL_Event event;

    while (running){

        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        while (SDL_PollEvent(&event)) {

            switch (event.type) {

                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        Properties::window->resize();

                    break;

                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    KeyboardHandler::handleKeyboardEvent(event);
                    break;

                default:
                    break;

            }
        }

        if (KeyboardHandler::isKeyPressed(SDLK_z)) caterpillar->addAimingAngle(2);
        if (KeyboardHandler::isKeyPressed(SDLK_q)) {

            caterpillar->setLooksRight(false);
            caterpillar->move(-3, 0);

        }

        if (KeyboardHandler::isKeyPressed(SDLK_s)) caterpillar->addAimingAngle(-2);
        if (KeyboardHandler::isKeyPressed(SDLK_d)){

            caterpillar->setLooksRight(true);
            caterpillar->move(3, 0);

        }

        if (KeyboardHandler::isKeyPressed(SDLK_RETURN) &&
        caterpillar->isOnGround()) caterpillar->addVelocity(0, -40);
        if (KeyboardHandler::isKeyPressed(SDLK_SPACE) &&
        Utils::getTimestamp() - caterpillar->getLastFire() > 1000) caterpillar->fire();

        if (KeyboardHandler::isKeyPressed(SDLK_F11))
            Properties::window->setFullscreen(
                    Properties::window->isFullscreen() ?
                    0 :
                    SDL_WINDOW_FULLSCREEN_DESKTOP);

        if (KeyboardHandler::isKeyPressed(SDLK_ESCAPE)) {

            running = false;
            continue;

        }

        Properties::game->update();
        Properties::window->draw(Properties::game);

        if (i >= 62){

            i = 0;
            caterpillar->nextTexture();
            Properties::window->setTitle(
                    std::string(Properties::programName)
                            .append(" - v")
                            .append(Properties::version)
                            .append(" - ")
                            .append(std::to_string(1000.f / (Utils::getTimestamp() - start) * 62))
                            .append(" FPS"));
            start = Utils::getTimestamp();

        }

        ++i;

    }

    TTF_CloseFont(Properties::font);
    Properties::font = nullptr;
    delete Properties::game;
    delete Properties::window;
    TextureHandler::deleteTextures();

    return EXIT_SUCCESS;

}