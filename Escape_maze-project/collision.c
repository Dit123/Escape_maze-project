#include <SDL2/SDL.h>
#include "collision.h"

int CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
// Check for collision between two rectangular objects
return (
        x1 < x2 + w2 &&
        x1 + w1 > x2 &&
        y1 < y2 + h2 &&
        y1 + h1 > y2
    );
}
int Collision_CheckCollision(const SDL_Rect* rectA, const SDL_Rect* rectB) {
    // Check for collision using SDL's built-in SDL_HasIntersection function
    return SDL_HasIntersection(rectA, rectB);
}
