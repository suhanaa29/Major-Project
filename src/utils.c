#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "monster.h"

void print_player(Player *p) {
    printf("Player: %s\n", p->player_name);
    printf("Team (%d):\n", p->team_count);
    for (int i=0;i<p->team_count;i++) {
        Monster *m = &p->team[i];
        printf(" %d) %s Lv%d HP:%d/%d\n", i+1, m->name, m->level, m->hp, m->max_hp);
    }
    printf("Potions: %d, Tame Orbs: %d\n", p->potions, p->tame_orbs);
}

void create_starter(Player *p, int choice) {
    if (choice == 1) init_monster(&p->team[0], 1, "Pyrokit", 3);
    else if (choice == 2) init_monster(&p->team[0], 2, "Aquarry", 3);
    else init_monster(&p->team[0], 3, "Terron", 3);
    p->team[0].is_catched = 1;
    p->team_count = 1;
}