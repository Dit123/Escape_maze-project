#include <stdio.h>
#include <stdlib.h>
#include "config.h"
Config gameConfig = {
    .screenWidth = 800,
    .screenHeight = 600,
    .soundEnabled = 1,
};


int LoadConfig(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Config file not found. Using default settings.\n");
        return 0;
    }

    if (fread(&gameConfig, sizeof(Config), 1, file) != 1) {
        printf("Error reading config file. Using default settings.\n");
    }

    fclose(file);
    return 1;
}

int SaveConfig(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving config file.\n");
        return 0;
    }

    if (fwrite(&gameConfig, sizeof(Config), 1, file) != 1) {
        printf("Error writing config file.\n");
    }

    fclose(file);
    return 1;
}

int configureGame() {
    // Modify the configuration here if needed
    gameConfig.screenWidth = 1024;

    // Example usage of LoadConfig and SaveConfig functions
    if (LoadConfig("config.dat")) {
        printf("Loaded configuration:\n");
        printf("Screen Width: %d\n", gameConfig.screenWidth);
        printf("Screen Height: %d\n", gameConfig.screenHeight);
        printf("Sound Enabled: %d\n", gameConfig.soundEnabled);
    } else {
        printf("Failed to load configuration.\n");
    }

    if (SaveConfig("config.dat")) {
        printf("Saved configuration to file.\n");
    } else {
        printf("Failed to save configuration.\n");
    }

    return 0;
}
