#include <stdio.h>
#include <string.h>
#include "monster.h"

// Helper to set base stats (simple formula)
void init_monster(Monster *m, int id, const char *name, int level) {
    m->id = id;
    strncpy(m->name, name, MAX_NAME_LEN-1);
    m->name[MAX_NAME_LEN-1] = '\0';
    m->level = level;
    m->max_hp = 20 + level * 5;
    m->hp = m->max_hp;
    m->attack = 5 + level * 2;
    m->defense = 3 + level;
    m->speed = 5 + level;
    m->exp = 0;
    m->exp_to_next = 10 + level * 5;
    m->is_catched = 0;
}

// Create simple wild monsters based on zone (0=forest,1=cave,2=lake)
Monster wild_monster_by_zone(int zone) {
    Monster m;
    if (zone == 0) init_monster(&m, 100 + zone, "Ferralyn", 1);
    else if (zone == 1) init_monster(&m, 110 + zone, "Cavernox", 2);
    else init_monster(&m, 120 + zone, "Aqualit", 3);
    return m;
}

void level_up_if_needed(Monster *m) {
    while (m->exp >= m->exp_to_next) {
        m->exp -= m->exp_to_next;
        m->level++;
        m->max_hp += 5;
        m->attack += 2;
        m->defense += 1;
        m->speed += 1;
        m->hp = m->max_hp;
        m->exp_to_next = 10 + m->level * 5;
        // could add learnable abilities here
        printf("%s leveled up to %d!\n", m->name, m->level);
    }
}