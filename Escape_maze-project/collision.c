#include <SDL2/SDL.h>
#include "collision.h"

// Check for collision between two rectangular objects
int Collision_CheckCollision(const SDL_Rect* rectA, const SDL_Rect* rectB) {
    // Check for collision using SDL's built-in SDL_HasIntersection function
    return SDL_HasIntersection(rectA, rectB);
}

