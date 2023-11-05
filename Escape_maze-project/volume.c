#include <stdio.h>
#include <stdlib.h>
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
        scanf("%d", &choice);

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
