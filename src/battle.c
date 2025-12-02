#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "battle.h"
#include "save_load.h"

static int basic_attack(Monster *att, Monster *def) {
    int dmg = att->attack - def->defense/2;
    if (dmg < 1) dmg = 1;
    def->hp -= dmg;
    if (def->hp < 0) def->hp = 0;
    return dmg;
}

int battle(Player *player, Monster wild) {
    if (player->team_count == 0) {
        printf("You have no monsters to fight with!\n");
        return 0;
    }
    Monster *pmon = &player->team[0]; // simplified: first monster fights
    printf("Battle start! %s (Lv %d) vs Wild %s (Lv %d)\n",
        pmon->name, pmon->level, wild.name, wild.level);

    srand((unsigned)time(NULL));
    while (pmon->hp > 0 && wild.hp > 0) {
        printf("\nYour %s HP: %d/%d | Wild %s HP: %d/%d\n",
            pmon->name, pmon->hp, pmon->max_hp, wild.name, wild.hp, wild.max_hp);
        printf("Choose action: 1) Attack  2) Use Potion  3) Throw Tame Orb  4) Run\n> ");
        int choice;
        if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); choice = 1; }
        if (choice == 1) {
            int dmg = basic_attack(pmon, &wild);
            printf("%s hit wild %s for %d damage!\n", pmon->name, wild.name, dmg);
        } else if (choice == 2) {
            if (player->potions > 0) {
                player->potions--;
                pmon->hp += 20;
                if (pmon->hp > pmon->max_hp) pmon->hp = pmon->max_hp;
                printf("Used potion. %s HP is now %d\n", pmon->name, pmon->hp);
            } else printf("No potions left!\n");
        } else if (choice == 3) {
            if (player->tame_orbs > 0) {
                player->tame_orbs--;
                int chance = 30 + (pmon->level - wild.level)*5;
                if (chance < 10) chance = 10;
                int roll = rand() % 100;
                if (roll < chance) {
                    printf("Success! You tamed %s.\n", wild.name);
                    wild.is_catched = 1;
                    // add to team if space
                    if (player->team_count < TEAM_SIZE) {
                        player->team[player->team_count++] = wild;
                    } else {
                        printf("Team is full — cannot add, but it's yours in storage.\n");
                    }
                    return 1;
                } else {
                    printf("Tame failed.\n");
                }
            } else printf("No Tame Orbs!\n");
        } else {
            // run attempt
            int run = rand() % 100;
            if (run < 50) { printf("You ran away.\n"); return 0; }
            else printf("Couldn't escape!\n");
        }

        // wild attacks if alive
        if (wild.hp > 0) {
            int dmg = basic_attack(&wild, pmon);
            printf("Wild %s hits %s for %d damage!\n", wild.name, pmon->name, dmg);
        }
    }

    if (pmon->hp <= 0) {
        printf("%s fainted...\n", pmon->name);
        return 0;
    } else if (wild.hp <= 0) {
        printf("You defeated %s!\n", wild.name);
        // reward exp
        int gain = 5 + wild.level * 3;
        player->team[0].exp += gain;
        printf("%s gained %d EXP.\n", player->team[0].name, gain);
        level_up_if_needed(&player->team[0]);
        return 1;
    }
    return 0;
}