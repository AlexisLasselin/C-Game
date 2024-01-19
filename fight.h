#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "map.h"

struct enemy {
    char name[20];
    int health;
    int damage;
    int defense;
};

struct player {
    char name[20];
    int health;
    int damage;
    int defense;
};

struct player player = {"You", 100, 20, 10};

// Function declarations
void fight(struct enemy *enemy);
void bossFight(void);
void attack(struct player *p, struct enemy *e);
void defend(struct player *p, struct enemy *e);
int getRandomNumber(int min, int max);
void displayLootboxResult(void);
int calculateVariableDamage(int baseDamage);
void gameOver(void);
void updatePlayerPosition(int newX, int newY, int maze[][COLS]);
void move(int newX,int newY,int maze[ROWS][COLS]);

struct enemy goblin = {"Goblin", 50, 5, 5};

void fight(struct enemy *enemy) {

    int choice;

    do {
        printf("Player Health: %d\n", player.health);
        printf("%s Health: %d\n", enemy->name, enemy->health);
        printf("What do you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                attack(&player, enemy);
                break;
            case 2:
                defend(&player, enemy);
                break;
            // case 3:
            //     printf("You ran away!\n");
            //     break;
            default:
                printf("Invalid choice. Try again.\n");
                fight(enemy);
                break;
        }

        // Check if the enemy is defeated
        if (enemy->health <= 0) {
            printf("You have defeated %s!\n", enemy->name);
            if (strcmp(enemy->name, "Sans") == 0) {
                printf("You have unlocked the Genocide route!\n");
                player.damage += 10;
                enemy->health = 200;
            } else if (strcmp(enemy->name, "Rick Astley") == 0) {
                printf("You're immune to the Rick Roll!\n");
                player.defense += 10;
                enemy->health = 200;
            } else if (strcmp(enemy->name, "Shrek") == 0) {
                printf("You have free access to the swamp!\n");
                player.health += 10;
                enemy->health = 200;
            }
            goblin.health = 50;
            break;
        }

        // Enemy's turn
        printf("%s attacks!\n", enemy->name);
        int enemyAttack = calculateVariableDamage(enemy->damage);
        int damageTaken = enemyAttack - player.defense;
        if (damageTaken > 0) {
            player.health -= damageTaken;
            printf("You took %d damage!\n", damageTaken);
        } else {
            printf("You blocked the attack!\n");
        }

         // Check if the player is defeated
        if (player.health <= 0) {
            clearScreen();
            if(strcmp(enemy->name,"Sans") == 0) {
                printf("                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                      \n"); 
                printf("                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               \n");  
                printf("                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@            \n");  
                printf("            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        \n");  
                printf("        ,,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,    \n");  
                printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    \n");
                printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  \n");  
                printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  \n");  
                printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");  
                printf("/@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@ \n"); 
                printf("/@@@@@@@@                       @@@@@@@@@@@@@@@                       @@@@@@ \n"); 
                printf("/@@@@@@                         @@@@@@@@@@@@@@@                         @@@@ \n"); 
                printf("/@@@@@@          @@@@           @@@@@@@@@@@@@@@        @@@@,            @@@@ \n"); 
                printf("/@@@@@@          @@@@           @@@@@@@@@@@@@@@        @@@@,            @@   \n"); 
                printf("    @@@@@@                     @@@@@@@@  /@@@@@@                       @@@@  \n");  
                printf("    ,,@@@@@@%%%%               @@@@@@       @@@@@@               %%%%@@,,    \n");  
                printf("        @@@@@@@@@@@@@@@@@@@  @@@@@@           @@@@@@  @@@@@@@@@@@@@@@@@      \n");  
                printf("        @@@@@@@@@@@@@@     @@@@@@@@           @@@@@@@@    @@@@@@@@@@@@@@@    \n");  
                printf("        @@@@@@@@  @@@@@@@@@@@@@@@@@           @@@@@@@@@@@@@@@@@@@@@@@@@@@    \n");  
                printf("    @@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@, ,@@@@@@@@@@@@    \n");
                printf("    @@@@@@@@       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@, ,@@@@@@@@@@@@    \n");
                printf("    @@@@@@@@@@@@    ,@@                                 @@, ,@@@@@@@@@@@@    \n");
                printf("    @@@@@@@@@@@@@@, ,@@  @@@@  @@@@@@  /@@@@@@  @@@@  @@   @@@@@@@@@@@@@@    \n");
                printf("    @@@@@@@@@@@@@@@@     @@@@  @@@@@@  /@@@@@@  @@@@    @@@@@@@@@@@@@@@      \n");
                printf("        @@@@@@@@@@@@@@@@@  @@@@  @@@@@@  /@@@@@@  @@@@  @@@@@@@@@@@@@@@@@    \n");  
                printf("        @@@@@@@@@@@@@@@@@                           @@@@@@@@@@@@@@@@@        \n");
                printf("                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               \n");  
                printf("                    ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                     \n");



                
            } else if (strcmp(enemy->name,"Rick Astley") == 0) {
                system("rick.bat");
            } else if (strcmp(enemy->name,"Shrek") == 0) {
                printf("You were defeated by Shrek. Game ogre!\n");
            } else if (strcmp(enemy->name,"Goblin") == 0) {
                printf("You were defeated by a goblin. So bad!\n");
            } else if (strcmp(enemy->name,"Dragon") == 0) {
                printf("You were defeated by a dragon. You got roasted!\n");
            } 
            gameOver();
        }

    } while (enemy->health > 0);
}

void bossFight(void) {
    srand(time(NULL));

    // Define bosses
    struct enemy sans = {"Sans", 200, 50, 20};
    struct enemy rickAstley = {"Rick Astley", 200, 75, 15};
    struct enemy shrek = {"Shrek", 200, 50, 40};

    // Generate a random number between 1 and 3 to choose a boss
    int randomBoss = rand() % 3 + 1;

    switch (randomBoss) {
        case 1:
            printf("You have encountered Sans!\n");
            printf("Sans: Hey buddy, it's a beautiful day outside. Birds are singing, flowers are blooming...\n");
            printf("Sans: On days like these, kids like you...\n");
            printf("Sans: Should be burning in heck.\n");
            fight(&sans);
            break;
        case 2:
            printf("You have encountered Rick Astley!\n");
            printf("Rick Astley: Never gonna give you up, never gonna let you down...\n");
            printf("Rick Astley: Never gonna run around and desert you...\n");
            printf("Rick Astley: Never gonna make you cry, never gonna say goodbye...\n");
            printf("Rick Astley: Never gonna tell a lie and hurt you.\n");
            fight(&rickAstley);
            break;

        case 3:
            printf("Uh oh! You encountered Shrek!\n");
            printf("Shrek: What are you doing in my swamp?! Get out!\n");
            fight(&shrek);
            break;

        default:
            printf("Invalid boss encountered. Exiting.\n");
            exit(EXIT_FAILURE);

    }

}

void attack(struct player *p, struct enemy *e) {
    clearScreen();
    int damageDealt = calculateVariableDamage(p->damage);
    if (damageDealt > 0) {
        e->health -= damageDealt;
        printf("You dealt %d damage!\n", damageDealt);
    } else {
        printf("Your attack was blocked!\n");
    }
}

void defend(struct player *p, struct enemy *e) {
    clearScreen();
    // Add logic for defending, e.g., increasing player's defense
    p->defense += getRandomNumber(1, 5); // Randomly increase defense by 1 to 5 points
    printf("You chose to defend. Your defense is increased.\n");
}

int calculateVariableDamage(int baseDamage) {
    int variability = getRandomNumber(-5, 5); // Introduce variability in damage
    int calculatedDamage = baseDamage + variability;
    return (calculatedDamage > 0) ? calculatedDamage : 0;
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void displayLootboxResult() {
    srand(time(NULL));

    printf("\nYou opened the chest and got:\n");

    // Updated loot items
    const char* lootItems[] = {"BF Gun", "Cookie", "Crewmate Suit", "Clementine", "Nothing", "ALGOSUP Diploma", "Daniel's class", "A rubik's cube", "A harfang"};

    // Determine the randomly chosen item
    int itemIndex = getRandomNumber(0, 7);  // 0 to 5 corresponds to BF Gun, Cookie, Crewmate Suit, Clementine, Nothing and ALGOSUP Diploma
    const char* lootItem = lootItems[itemIndex];

    printf(">> %s\n", lootItem);
    if (strcmp(lootItem, "BF Gun") == 0) {
        printf("You got a BF Gun! You can now shoot your enemies! ⌐╦╦═─\n");
        player.damage += 45;
        printf("Your damage is now %d!\n", player.damage);
    } else if (strcmp(lootItem, "Cookie") == 0) {
        printf("You got a cookie! You can now heal yourself!\n");
        player.health += 20;
        printf("Your health is now %d!\n", player.health);
    } else if (strcmp(lootItem, "Crewmate Suit") == 0) {
        printf("You got a crewmate suit! Watch out for impostors!\n");
        player.defense += 10;
        printf("Your defense is now %d!\n", player.defense);
    } else if (strcmp(lootItem, "Clementine") == 0) {
        printf("You got a clementine! You can now summon Clementine!\n");
        player.damage += 15;
        player.defense += 20;
        player.health *= 2;
        printf("Clementine: I'm Clementine! I'm here to help!\n");
        printf("Your damage is now %d!\n", player.damage);
        printf("Your defense is now %d!\n", player.defense);
        printf("Your health is now %d!\n", player.health);
    } else if (strcmp(lootItem, "Nothing") == 0) {
        printf("You got nothing! Better luck next time!\n");
        printf("Emotional Damage: +10\n");
        player.health -= 10;
        printf("You took 10 damage!\n");
        printf("You now have %d health.\n", player.health);
    } else if (strcmp(lootItem, "ALGOSUP Diploma") == 0) {
        printf("NO WAY! You got the item that no one has ever gotten before!\n");
        printf("You got the ALGOSUP Diploma! You can now graduate!\n");
        printf("You have unlocked the Secret Ending!\n");
        printf("You won the game!\n");
        printf("press any key to exit\n");
        getchar();
        exit(EXIT_SUCCESS);
    } else if (strcmp(lootItem, "Daniel's class") == 0) {
        printf("You got Daniel's class! You're really unlucky!\n");
        gameOver();
        exit(EXIT_SUCCESS);
    } else if (strcmp(lootItem, "A rubik's cube") == 0) {
        printf("You got a rubik's cube! You can now solve it!\n");
        printf("Welcome to the God mode!\n");
        player.damage += 100;
        player.defense += 100;
        player.health += 100;
        printf("Your damage is now %d!\n", player.damage);
        printf("Your defense is now %d!\n", player.defense);
        printf("Your health is now %d!\n", player.health);
    } else if (strcmp(lootItem, "A harfang") == 0) {
        printf("You got a harfang! You can try to tame it!\n");
        printf("You successfully tamed the harfang but\n");
        printf("it pierced your eye\n");
        printf("You lost 50 health\n");
        player.health -= 50;
    }
}


void gameOver(void) {
    printf("press any key to exit\n");
    getchar();
    exit(EXIT_SUCCESS);
}

void move(int newX,int newY,int maze[ROWS][COLS]) {
    updatePlayerPosition(newX, newY, maze);
    }

void updatePlayerPosition(int newX, int newY, int maze[][COLS]) {
    maze[playerY][playerX] = EMPTY;
    maze[newY][newX] = PLAYER;
    playerX = newX;
    playerY = newY;
}