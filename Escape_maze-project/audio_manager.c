#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    } else {
        // Initialize SDL_Mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            fprintf(stderr, "SDL_Mixer initialization failed: %s\n", Mix_GetError());
            return 1;
        }
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("background_music.mp3");
    if (!backgroundMusic) {
        fprintf(stderr, "Mix_LoadMUS: %s\n", Mix_GetError());
        return 1;
    }

    Mix_Chunk *soundEffect = Mix_LoadWAV("explosion.wav");
    if (!soundEffect) {
        fprintf(stderr, "Mix_LoadWAV: %s\n", Mix_GetError());
        return 1;
    }

    // ... Your audio-related code ...

    Mix_FreeMusic(backgroundMusic);
    Mix_FreeChunk(soundEffect);

    // ... Rest of your code ...

    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

