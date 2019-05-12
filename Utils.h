//
// Created by Paragoumba on 24/04/19.
//

#ifndef CATERPILLARS_UTILS_H
#define CATERPILLARS_UTILS_H

class Utils {
public:
    Utils() = delete;

    static long getTimestamp();
    static void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int circleThickness = 1);
    static void fillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);
};

#endif //CATERPILLARS_UTILS_H
