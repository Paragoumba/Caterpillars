//
// Created by Paragoumba on 24/04/19.
//

#ifndef CATERPILLARS_TEXTUREHANDLER_H
#define CATERPILLARS_TEXTUREHANDLER_H

#include <string>
#include <map>
#include <SDL2/SDL_render.h>

class TextureHandler {
private:
    static std::string resDir;
    static std::map<std::string, SDL_Texture*> textures;
public:
    static const std::string CATERPILLAR0_TEXTURE;
    static const std::string CATERPILLAR1_TEXTURE;
    static const std::string CATERPILLAR2_TEXTURE;
    static const std::string BULLET_TEXTURE;

    TextureHandler() = delete;

    static SDL_Texture* getTexture(const std::string& textureName);
    static void initTexture(const std::string& textureName);
    static void deleteTextures();
};

#endif //CATERPILLARS_TEXTUREHANDLER_H
