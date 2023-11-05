#include "config.h"
#include <stdio.h>
#include <stdlib.h>

// Define default configuration values
Config gameConfig = {
    .screenWidth = 800,
    .screenHeight = 600,
    .soundEnabled = 1,
};

// Function to load configuration from a file
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

// Function to save configuration to a file
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

