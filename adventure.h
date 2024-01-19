#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "fight.h"

bool getMap = false;
int THINKING = 0;
int playerX, playerY;  // Assuming these are global variables
bool hasKey = false;

// Function declarations
void start(void);
void chooseAtStart(void);
void thinking(void);
void lightStart(void);
void movement(void);
void checkKey(int newX, int newY, int maze[][COLS], bool hasKey);
void randomEvent(void);

void start(void) {
    clearScreen();
    printf("You wake up, and find yourself in a dark room. You can't remember anything.\nBecause of the absence of light, you can't see anything. What do you do?\n");

    chooseAtStart();
}

void chooseAtStart() {
    char choice;
    printf("Stay in the room and think about your situation (s) or Try to find a way out (f)\n");
    scanf(" %c", &choice);

    if (choice == 's' || choice == 'S') {
        clearScreen();
        thinking();
    } else if (choice == 'f' || choice == 'F') {
        clearScreen();
        movement();
    } else {
        printf("Please enter a valid option.\n");
        chooseAtStart();
    }
}

void thinking() {
    clearScreen();
    THINKING++;
    if (THINKING == 1) {
        printf("You may get an idea if you think a little longer.\n");
        chooseAtStart();
    } else if (THINKING == 2) {
        printf( "  ..---..    \n"
                " /       \\  \n"
                "|         |  \n"
                ":         ;  \n"
                " \\  \\~/  / \n"
                "  `, Y ,'    \n"
                "   |_|_|     \n"
                "   |===|     \n"
                "   |===|     \n"
                "    \\_/     \n");

        printf("EUREKA! You got an idea! You can grab the bulb from your idea and use it as a light source.\n");
        lightStart();
    }
}

void lightStart(void) {
    printf("You can see now. You're in a room with a door and a map on the wall, you can see the map now.\n");
    getMap = true;

    movement();
}

void isValidMov(int newX, int newY, int maze[ROWS][COLS]) {
    if (maze[newY][newX] == 0) {
        clearScreen();
        move(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 20) {
        clearScreen();
        fight(&goblin);
        move(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 4 ) {
        clearScreen();
        bossFight();
        move(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 8 || maze[newY][newX] == 19) {
        clearScreen();
        checkKey(newX, newY, maze, hasKey);
        movement();
    } else if (maze[newY][newX] == 5) {
        clearScreen();
        displayLootboxResult();
        move(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 6) {
        clearScreen();
        srand(time(NULL));
        randomEvent();
        move(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 7) {
        clearScreen();
        printf("You found a key!\n You can now open doors.\n");
        hasKey = true;
        updatePlayerPosition(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 3) {
        clearScreen();
        printf("Congratulations! You escaped the maze!\n");
        exit(EXIT_SUCCESS);
    } else {
        clearScreen();
        printf("You can't go there.\n");
        movement();
    }
}

void movement(void) {
    int newX, newY;
    char direction;

    if (getMap == true) {
        displayMap(maze);
    }

    printf("Which direction do you want to go? (w, a, s, d)\n");
    scanf(" %c", &direction);

    printf("You chose %c\n", direction);

    if (direction == 'w' || direction == 'W') {
        newX = playerX;
        newY = playerY - 1;
        isValidMov(newX, newY, maze);
    } else if (direction == 'a' || direction == 'A') {
        newX = playerX - 1;
        newY = playerY;
        isValidMov(newX, newY, maze);
    } else if (direction == 's' || direction == 'S') {
        newX = playerX;
        newY = playerY + 1;
        isValidMov(newX, newY, maze);
    } else if (direction == 'd' || direction == 'D') {
        newX = playerX + 1;
        newY = playerY;
        isValidMov(newX, newY, maze);
    } else {
        printf("Please enter a valid option.\n");
        movement();
    }
}

void checkKey(int newX, int newY, int maze[][COLS], bool hasKey) {
    if (hasKey == true) {
        updatePlayerPosition(newX, newY, maze);
    } else {
        printf("You don't have the key.\n");
    }
}

void randomEvent(void) {
    int event = getRandomNumber(1, 3);
    if (event == 1) {
        printf("You woke up a giant dragon!\n");
        struct enemy dragon = {"Dragon", 1000, 50, 20};
        fight(&dragon);
    } else if (event == 2) {
        printf("You found a lootbox!\n");
        displayLootboxResult();
    } else if (event == 3) {
        printf("You fall into a trap!\n");
        player.health /= 2;
    }
}