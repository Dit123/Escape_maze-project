#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "volume.h"
#include "auth.h"
#include "enums.h"


enum GameState gameState = MENU;

int displayMenu() {
    printf("Welcome to My Game\n");
    printf("1. About the Game\n");
    printf("2. Sign In and Play\n");
    printf("3. High Score\n");
    printf("4. Adjust Volume\n");
    printf("5. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}


void performAction(int choice) {
    switch (choice) {
        case 1:
            printf("About the Game:\n");
            printf("This is an exciting adventure game. Learn more about it!\n");
             printf("Escape Maze: The Treasure Hunt\n");
    printf("\n");
    printf("Description:\n");
    printf("Escape Maze is an exhilarating adventure game that puts your problem-solving skills and quick thinking to the ultimate test. In this thrilling escapade, players must navigate through a series of challenging mazes, racing against time to find the hidden treasure while avoiding cunning enemies that are hot on their heels.\n");
    printf("\n");
    printf("Story:\n");
    printf("Set in the heart of an ancient, mysterious jungle, the Escape Maze game begins as you, the daring explorer, stumble upon a long-forgotten legend of a hidden treasure buried deep within the labyrinthine maze. As the legend goes, the treasure holds immeasurable riches, but it's not easy to obtain. It's said that those who dare to venture into the maze must conquer numerous obstacles and evade cunning adversaries who guard the treasure with their lives.\n");
    printf("\n");
    printf("Your journey commences as you step foot into the overgrown, labyrinthine maze, your heart racing with anticipation. The twists and turns of the maze are fraught with danger, from intricate puzzles to perplexing riddles that challenge your intellect and wit. As you delve deeper, time becomes your nemesis, ticking away relentlessly, urging you to quicken your pace in the pursuit of the ultimate prize.\n");
    printf("\n");
    printf("But beware, for lurking in the shadows are ruthless enemies, guardians of the treasure, who are relentless in their pursuit to thwart your progress. You must outsmart them, evade their cunning traps, and stay one step ahead, for capture means starting all over, and time is running out.\n");
    printf("\n");
    printf("Escape Maze offers an immersive experience that combines strategy, problem-solving, and quick decision-making. Do you have what it takes to outsmart the enemies, decipher the riddles, and unearth the legendary treasure before it's too late? Embark on this heart-pounding adventure and put your skills to the test. The treasure awaits, but only the most cunning and swift can claim it.\n");

            break;
        case 2:
            printf("Sign In:\n");
            printf("Sign-in successful! Get ready to play.\n")
            system("./game");
            break;
        case 3:
            printf("High Score:\n");
            printf("Your highest score is: 1000\n");
            // Display user's high score and other progress information.
            break;
        case 4:
            printf("Adjust Volume:\n");
            printf("Volume settings updated!\n");
            adjustVolume();
            break;
        case 5:
            printf("Exiting the game. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

int main() {
    bool exitProgram = false;

    while (!exitProgram) {
        int choice = displayMenu();
        performAction(choice);

	 char inputUsername[50];
	 char inputPassword[50];

    printf("Welcome to Escape Maze!\n");

    // Prompt the user to sign in
    printf("Please sign in:\n");
    printf("Username: ");
    scanf("%s", inputUsername);
    printf("Password: ");
    scanf("%s", inputPassword);
    // Authenticate the user
    if (authenticateUser(inputUsername, inputPassword)) {
        printf("Sign-in successful. You are now ready to play the game!\n");
        // Add code here to start the game.
    } else {
        printf("Authentication failed. Please check your username and password.\n");
    }

    return 0;
}
        // Ask the user if they want to continue
        char response;
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &response);

        if (response == 'n' || response == 'N') {
            exitProgram = true;
        }
    }

    return 0;
}

