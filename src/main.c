#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monster.h"
#include "battle.h"
#include "save_load.h"
#include "utils.h"

int main() {
    Player player;
    memset(&player, 0, sizeof(Player));
    strcpy(player.player_name, "Tamer");
    player.potions = 3;
    player.tame_orbs = 3;

    printf("== Monster Tamer RPG (Prototype) ==\n");

    // Starter selection
    printf("Choose starter: 1) Pyrokit  2) Aquarry  3) Terron\n> ");
    int s=1;
    if (scanf("%d", &s) != 1) { while (getchar()!='\n'); s=1; }
    create_starter(&player, s);

    int running = 1;
    while (running) {
        printf("\nMain Menu: 1) Explore  2) Team  3) Save  4) Load  5) Quit\n> ");
        int c;
        if (scanf("%d", &c) != 1) { while (getchar()!='\n'); c=1; }
        if (c == 1) {
            printf("Choose zone: 0) Forest 1) Cave 2) Lake\n> ");
            int zone; if (scanf("%d", &zone) != 1) { while (getchar()!='\n'); zone=0; }
            Monster wild = wild_monster_by_zone(zone);
            int outcome = battle(&player, wild);
            (void)outcome;
        } else if (c == 2) {
            print_player(&player);
        } else if (c == 3) {
            if (save_player("savegame.bin", &player))
                printf("Game saved to savegame.bin\n");
            else printf("Save failed.\n");
        } else if (c == 4) {
            if (load_player("savegame.bin", &player))
                printf("Game loaded from savegame.bin\n");
            else printf("Load failed (no save present?).\n");
        } else {
            running = 0;
        }
    }

    printf("Bye!\n");
    return 0;
}