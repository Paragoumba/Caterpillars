//
// Created by Paragoumba on 24/04/19.
//

#include "TextureHandler.h"
#include "Properties.h"

std::string TextureHandler::resDir = "../res/";
std::map<std::string, SDL_Texture*> TextureHandler::textures;
const std::string TextureHandler::CATERPILLAR0_TEXTURE = "caterpillar0.bmp";
const std::string TextureHandler::CATERPILLAR1_TEXTURE = "caterpillar1.bmp";
const std::string TextureHandler::CATERPILLAR2_TEXTURE = "caterpillar2.bmp";
const std::string TextureHandler::BULLET_TEXTURE = "tinybullet.bmp";

SDL_Texture* TextureHandler::getTexture(const std::string& textureName){

    auto iterator = textures.find(textureName);

    if (iterator == textures.end()){

        SDL_Texture* texture = SDL_CreateTextureFromSurface(
                Properties::window->getRenderer(),
                SDL_LoadBMP((resDir + textureName/* + ".bmp"*/).c_str()));
        textures.insert(std::pair(textureName, texture));

        return texture;

    }

    return iterator->second;

}

void TextureHandler::initTexture(const std::string& textureName) {

    textures.insert(std::pair(
                    textureName,
                    SDL_CreateTextureFromSurface(
                            Properties::window->getRenderer(),
                            SDL_LoadBMP((resDir + textureName/* + ".bmp"*/).c_str()))));

}

void TextureHandler::deleteTextures() {

    for(auto it = textures.begin(); it != textures.end(); ++it)
        textures.erase(it);

}
