
#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

// Function to display the main menu and return the user's choice
int displayMenu();

// Function to perform actions based on the user's choice
void performAction(int choice);

// Function to authenticate the user (you can define this in a separate "auth.h" file)
bool authenticateUser(const char* username, const char* password);

#endif // MENU_H

