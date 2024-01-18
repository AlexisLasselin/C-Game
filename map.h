#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Purpose: Header file for map.c

// The map is a 2D array of integers.
// Each integer represents a different element in the maze.

// Map design
// 0  = Path; 1 = horizontal wall; 2 = Player; 3 = End; 4 = Boss; 5 = Chest; 6 = Trap; 7 = Key; 8 = Door; 9 = vertical wall; 
// 10 = Left Top Corner; 11 = Right Top Corner; 12 = Left Bottom Corner; 13 = Right Bottom Corner; 14 = Left T; 15 = Right T; 
// 16 = T; 17 = Bottom T; 18 = Cross; 19 = Vertical door; 20 = Basic enemy

int maze[10][30] =
{
{10, 1,16, 1, 1,1, 1, 1, 1,1,1, 1,1, 1,1, 1,16,1,16,16,1, 1,1,1,1, 1,1, 1,1,11},
{ 9, 7, 9, 0, 0,0, 0, 0,20,0,0, 0,0, 0,0, 0, 9,2,14,15,5, 0,0,0,0,20,0, 0,0, 9},
{ 9, 0,12, 1, 1,1,16, 1, 1,1,1, 1,1, 1,8,10,15,0,14,18,1, 1,1,1,1,16,8,11,0, 9},
{ 9, 0, 20, 0, 0,0, 0, 0,20,0,0, 0,0, 0,0,12,13,0,12,13,0,10,1,8,1,15,0, 9,0, 9},
{ 9, 8, 1,16,16,1,18, 1,16,1,1, 1,1, 1,0, 0, 0,20, 0, 0,0, 9,0,5,0,19,0, 9,6, 9},
{ 9, 0, 0,12,13,0,17, 0,12,1,1, 1,1, 1,1, 1, 1,8, 1, 1,1,17,1,1,1,13,0, 9,0, 9},
{14,11, 0, 0, 0,0, 0, 0,20,0,0, 0,0, 0,0, 0, 0,0, 0, 0,0, 0,0,0,0, 0,0, 9,0, 9},
{14,17, 8,10, 1,8,10,11, 8,1,1,11,0,10,1, 1, 1,1, 1, 1,1,16,1,1,1, 8,1,15,0, 9},
{ 9, 3, 6, 9, 5,4,14,15, 0,6,0, 9,8,13,0, 0, 0,4, 0, 0,0, 9,0,0,0, 4,0, 9,3, 9},
{12, 1, 1,17, 1,1,17,17, 1,1,1,17,1, 1,1, 1, 1,1, 1, 1,1,17,1,1,1, 1,1,17,1,13},
};

// Display the map with ascii characters

void displayMap(int map[10][30]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 30; j++) {
            if (map[i][j] == 10){
                printf("╔");
            } else if (map[i][j] == 1){
                printf("═");
            } else if (map[i][j] == 11){
                printf("╗");
            } else if (map[i][j] == 12){
                printf("╚");
            } else if (map[i][j] == 13){
                printf("╝");
            } else if (map[i][j] == 14){
                printf("╠");
            } else if (map[i][j] == 15){
                printf("╣");
            } else if (map[i][j] == 16){
                printf("╦");
            } else if (map[i][j] == 17){
                printf("╩");
            } else if (map[i][j] == 18){
                printf("╬");
            } else if (map[i][j] == 9){
                printf("║");
            } else if (map[i][j] == 0){
                printf(" ");
            } else if (map[i][j] == 2){
                printf("☺");
            } else if (map[i][j] == 3){
                printf("○");
            } else if (map[i][j] == 4){
                printf("☠");
            } else if (map[i][j] == 5){
                printf("★");
            } else if (map[i][j] == 6){
                printf("☀");
            } else if (map[i][j] == 7){
                printf("±");
            } else if (map[i][j] == 8){
                printf("─");
            } else if (map[i][j] == 19){
                printf("│");
            } else if (map[i][j] == 20){
                printf("☣");
            } else {
                printf("?");
            }
            
        }
        printf("\n");
    }
}