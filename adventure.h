#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "map.h"  // Assuming you have a header file for map-related functions

#define EMPTY 0
#define PLAYER 2

bool getMap = false;
int THINKING = 0;
int playerX, playerY;  // Assuming these are global variables

// Function declarations
void clearScreen(void);
void start(void);
void chooseAtStart(void);
void thinking(void);
void lightStart(void);
void randomEvent(void);
void movement(void);
void updatePlayerPosition(int newX, int newY, int maze[][COLS]);

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void start(void) {
    clearScreen();
    printf("You wake up, and find yourself in a dark room. You can't remember anything.\nBecause of the absence of light, you can't see anything. What do you do?\n");

    chooseAtStart();
}

void chooseAtStart() {
    char choice;
    printf("Stay in the room and think about your situation (s) or Try to find a way out (f)\n");
    scanf(" %c", &choice);

    if (choice == ('s' | 'S')) {
        clearScreen();
        thinking();
    } else if (choice == ('f' | 'F')) {
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

void randomEvent(void) {
#ifdef _WIN32
    system("main.bat");
#endif
}

void updatePlayerPosition(int newX, int newY, int maze[][COLS]) {
    maze[playerY][playerX] = EMPTY;
    maze[newY][newX] = PLAYER;
    playerX = newX;
    playerY = newY;
}

void isValidMov(int newX, int newY, int maze[ROWS][COLS]) {
    printf("%d, %d\n", newX, newY);
    printf("%d\n", maze[newY][newX--]);
    printf("%d\n", maze[newY][newX]);
    printf("%d\n", maze[newY][newX++]);
    if (maze[newY][newX] == 0) {
        // clearScreen();
        updatePlayerPosition(newX, newY, maze);
        movement();
    } else if (maze[newY][newX] == 20 || maze[newY][newX] == 4 ) {
        // clearScreen();
        // TODO: Implement fight system
        movement();
    } else if (maze[newY][newX] == 8 || maze[newY][newX] == 19) {
        // clearScreen();
        // TODO: Implement door system
        movement();
    } else if (maze[newY][newX] == 5) {
        // clearScreen();
        // TODO: Implement treasure system
    } else if (maze[newY][newX] == 6) {
        // clearScreen();
        randomEvent();
        movement();
    } else if (maze[newY][newX] == 7) {
        // clearScreen();
        // TODO: Implement key system
        movement();
    } else if (maze[newY][newX] == 3) {
        // TODO: Implement win system
    } else {
        // clearScreen();
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

    if (direction == ('w' | 'W')) {
        newX = playerX;
        newY = playerY - 1;
        isValidMov(newX, newY, maze);
    } else if (direction == ('a' | 'A')) {
        newX = playerX - 1;
        newY = playerY;
        isValidMov(newX, newY, maze);
    } else if (direction == ('s' | 'S')) {
        newX = playerX;
        newY = playerY + 1;
        isValidMov(newX, newY, maze);
    } else if (direction == ('d' | 'D')) {
        newX = playerX + 1;
        newY = playerY;
        isValidMov(newX, newY, maze);
    } else {
        printf("Please enter a valid option.\n");
        movement();
    }
}