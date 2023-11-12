#include <SDL2/SDL.h>
#include "collision.h"

int CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
// Check for collision between two rectangular objects
int Collision_CheckCollision(const SDL_Rect* rectA, const SDL_Rect* rectB) {
    // Check for collision using SDL's built-in SDL_HasIntersection function
    return SDL_HasIntersection(rectA, rectB);
}
