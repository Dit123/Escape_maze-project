#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

// Utility function to generate a random number in a given range
int RandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Utility function to clamp a value within a specified range
int Clamp(int value, int min, int max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

int utilitiesGame() {
    // Test the RandomNumber function
    printf("Random Number: %d\n", RandomNumber(1, 100));

    // Test the Clamp function
    int valueToClamp = 150;
    int minValue = 50;
    int maxValue = 100;
    int clampedValue = Clamp(valueToClamp, minValue, maxValue);
    printf("Clamped Value: %d\n", clampedValue);

    return 0;
}
