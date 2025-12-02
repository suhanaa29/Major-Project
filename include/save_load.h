#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "monster.h"

int save_player(const char *filename, Player *p);
int load_player(const char *filename, Player *p);

#endif