#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>
#endif

#include "map.h"

bool getMap = false;

int THINKING = 0;

// **********  FUNCTION DECLARATIONS  **********
void clearScreen(void);
void start(void);
void chooseAtStart(void);
void thinking(void);
void lightStart(void);
// *********************************************

void clearScreen(void){
    #ifdef _WIN32
        system("cls");
    #endif
        system("clear");
}

void start(void){
    clearScreen();
    printf("You wake up, and find yourself in a dark room. You can't remember anything. Because of the absence of light, you can't see anything. What do you do?\n");

    chooseAtStart();
}

void chooseAtStart(){
    char choice;
    printf("Stay in the room and think about your situation (s) \t or \t Try to find a way out (f)\n");
    scanf(" %c", &choice);

    if (choice == 's'){
        thinking();
    // } else if (choice == 'f'){
    //     getMap = true;
    //     getMap();
    } else {
        printf("Please enter a valid option.\n");
        chooseAtStart();
    }
}

void thinking() {
    clearScreen();
    THINKING++;
    if (THINKING == 1){
        printf("You may get an idea if you think a little longer.\n");
        chooseAtStart();
    } else if (THINKING == 2) {
        printf("  ..---..    \n");
        printf(" /       \\  \n");
        printf("|         |  \n");
        printf(":         ;  \n");
        printf(" \\  \\~/  / \n");
        printf("  `, Y ,'    \n");
        printf("   |_|_|     \n");
        printf("   |===|     \n");
        printf("   |===|     \n");
        printf("   |\\_/|    \n");

        printf("EUREKA!\n");
        printf("You grab the bulb from your idea, you're able to see now.\n");
        lightStart();
    }
}

void lightStart(void) {
    printf("You can see now. You're in a room with a door and a map on the wall, you can see the map now.\n");
    getMap = true;
    system("./main.bat");
}