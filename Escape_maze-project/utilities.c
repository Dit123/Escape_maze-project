#include "utilities.h"
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

