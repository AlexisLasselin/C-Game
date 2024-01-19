#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "map.h"  // map.h is the header file for the map

struct enemy {
    char name[20];
    int health;
    int damage;
    int defense;
    // Add any additional fields specific to each boss
};

struct player {
    char name[20];
    int health;
    int damage;
    int defense;
};

struct player player = {"You", 100, 20, 10};

struct enemy goblin = {"Goblin", 50, 5, 5};


void fight(struct enemy *enemy);
void bossFight(void);
void attack(struct player *p, struct enemy *e);
void defend(struct player *p, struct enemy *e);

void fight(struct enemy *enemy) {
    int choice;

    do {
        printf("Player Health: %d\n", player.health);
        printf("%s Health: %d\n", enemy->name, enemy->health);
        printf("What do you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                attack(&player, enemy);
                break;
            case 2:
                defend(&player, enemy);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        // Check if the enemy is defeated
        if (enemy->health <= 0) {
            printf("You have defeated %s!\n", enemy->name);
            if(strcmp(enemy->name,"Sans") == 0) {
                printf("You have unlocked the Genocide route!\n");
                player.damage += 10;
            } else if (strcmp(enemy->name,"Rick Astley") == 0) {
                printf("You're immune to the Rick Roll!\n");
                player.defense += 10;
            } else if (strcmp(enemy->name,"Shrek") == 0) {
                printf("You have a free access to the swamp!\n");
                player.health += 10;
            }
            break;
        }

        // Enemy's turn
        if (strcmp(enemy->name, "Goblin") == 0) {
            printf("Goblin: You're gonna die!\n");
        } else if(strcmp(enemy->name,"Sans") == 0) {
            printf("Sans: You're gonna have a bad time.\n");
        } else if (strcmp(enemy->name,"Rick Astley") == 0) {
            printf("Rick Astley: Never gonna give you up!\n");
        } else if (strcmp(enemy->name,"Shrek") == 0) {
            printf("Shrek: Get out of my swamp!\n");
        }
        printf("%s attacks!\n", enemy->name);
        int enemyAttack = enemy->damage - player.defense;
        if (enemyAttack > 0) {
            player.health -= enemyAttack;
            printf("You took %d damage!\n", enemyAttack);
        } else {
            printf("You blocked the attack!\n");
        }

        // Check if the player is defeated
        if (player.health <= 0) {
            printf("You were defeated by %s. Game over!\n", enemy->name);
            if(strcmp(enemy->name,"Sans")) {
                
            }
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
            fight(&sans);
            break;
        case 2:
            printf("You have encountered Rick Astley!\n");
            fight(&rickAstley);
            break;
        case 3:
            printf("You have encountered Shrek!\n");
            fight(&shrek);
            break;
        default:
            printf("Invalid boss encountered. Exiting.\n");
            exit(EXIT_FAILURE);
    }
}

void attack(struct player *p, struct enemy *e) {
    int damageDealt = p->damage - e->defense;
    if (damageDealt > 0) {
        e->health -= damageDealt;
        printf("You dealt %d damage!\n", damageDealt);
    } else {
        printf("Your attack was blocked!\n");
    }
}

void defend(struct player *p, struct enemy *e) {
    // Add logic for defending, e.g., increasing player's defense
    p->defense += 5;
    printf("You chose to defend. Your defense is increased.\n");
}