//
// Created by Paragoumba on 24/04/19.
//

#include <chrono>
#include <cmath>
#include <SDL2/SDL_render.h>
#include "Utils.h"

long Utils::getTimestamp() {

    return std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now()
            .time_since_epoch())
            .count();

}

void Utils::drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int circleThickness) {
                                                // centerX  and centerY are the position of
                                                // the center of the circle

    // Permits to work with even and odd radii
    float center = radius - 1 + (float)((radius * 2 + 1) % 2) / 2;
    float length;
    double radiusSquared = pow(radius, 2);
    double blankRadiusSquared = pow(radius - circleThickness, 2);

    // For each pixel in square around the circle
    // we draw the ones in the circle
    for (int i = 0; i < radius * 2; ++i){

        double lengthXSquared = pow(i - center, 2);

        for (int j = 0; j < radius * 2; ++j){

            length = lengthXSquared + pow(j - center, 2);

            // if distance between pixel in (i,j) and center <= radius squared
            if (length <= radiusSquared && length >= blankRadiusSquared)
                // Draws 1 pixel at (x + i,y + j) with a predefined color
                SDL_RenderDrawPoint(renderer, centerX + i, centerY + j);

        }
    }
}

void Utils::fillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {

    drawCircle(renderer, centerX, centerY, radius, radius);

}
