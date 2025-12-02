#include <stdio.h>
#include "save_load.h"

int save_player(const char *filename, Player *p) {
    FILE *f = fopen(filename, "wb");
    if (!f) return 0;
    fwrite(p, sizeof(Player), 1, f);
    fclose(f);
    return 1;
}

int load_player(const char *filename, Player *p) {
    FILE *f = fopen(filename, "rb");
    if (!f) return 0;
    if (fread(p, sizeof(Player), 1, f) != 1) { fclose(f); return 0; }
    fclose(f);
    return 1;
}