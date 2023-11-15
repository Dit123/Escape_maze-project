#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <ncurses.h>
#include <math.h>
#include "volume.h"

void adjustVolume() {
    int volume = 50;
    int choice;

    do {
        printf("\nCurrent Volume: %d\n", volume);
        printf("1. Increase Volume\n");
        printf("2. Decrease Volume\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");

        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                if (volume < 100) {
                    volume += 10;
                }
                break;
            case 2:
                if (volume > 0) {
                    volume -= 10;
                }
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (1);
}

int volumeGame() {
    // Your program logic, maybe calling adjustVolume or other functions
    adjustVolume();

    return 0;
}
