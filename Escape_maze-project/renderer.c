#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "renderer.h"

SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;

TTF_Font* g_font = NULL;

int Renderer_Init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL couldn't be initialized: %s\n", SDL_GetError());
        return -1;
    }

    // Create a window
    g_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!g_window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        return -1;
    }

    // Create a renderer
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if (!g_renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        return -1;
    }

    // Initialize SDL_image for loading textures
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Failed to initialize SDL_image: %s\n", IMG_GetError());
        return -1;
    }

    // Initialize SDL_ttf for font rendering
    if (TTF_Init() < 0) {
        printf("SDL_ttf couldn't be initialized: %s\n", TTF_GetError());
        return -1;
    }

    // Initialize the font (using Arial as an example)
    const char* fontFile = "arial.ttf";  // Replace with the appropriate font file on your system
    int fontSize = 24;
    g_font = TTF_OpenFont(fontFile, fontSize);
    if (!g_font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return -1;
    }

    return 0;
}

SDL_Texture* Renderer_LoadTexture(const char* filename) {
    SDL_Texture* texture = IMG_LoadTexture(g_renderer, filename);
    if (!texture) {
        printf("Failed to load texture: %s\n", IMG_GetError());
    }
    return texture;
}

void Renderer_Clear() {
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
    SDL_RenderClear(g_renderer);
}

void Renderer_DrawTexture(SDL_Texture* texture, int x, int y) {
    SDL_Rect dstRect = {x, y, 0, 0};
    SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
    SDL_RenderCopy(g_renderer, texture, NULL, &dstRect);
}

void Renderer_Render() {
    SDL_RenderPresent(g_renderer);
}

void Renderer_Close() {
    if (g_renderer) {
        SDL_DestroyRenderer(g_renderer);
        g_renderer = NULL;
    }
    if (g_window) {
        SDL_DestroyWindow(g_window);
        g_window = NULL;
    }
    IMG_Quit();

    // Close and free the font
    if (g_font) {
        TTF_CloseFont(g_font);
        g_font = NULL;
    }

    TTF_Quit();
    SDL_Quit();
}

int main() {
    return 0;
}
