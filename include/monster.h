#ifndef MONSTER_H
#define MONSTER_H

#define MAX_NAME_LEN 32
#define TEAM_SIZE 6

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int level;
    int hp;
    int max_hp;
    int attack;
    int defense;
    int speed;
    int exp;        // current exp
    int exp_to_next;
    int is_catched; // 1 if in player team
} Monster;

typedef struct {
    char player_name[64];
    Monster team[TEAM_SIZE];
    int team_count;
    int potions;
    int tame_orbs;
} Player;

void init_monster(Monster *m, int id, const char *name, int level);
Monster wild_monster_by_zone(int zone); // returns a Monster (by value)
void level_up_if_needed(Monster *m);

#endif