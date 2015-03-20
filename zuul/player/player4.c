// Player (Ausbaustufe 3: Prozedur readline aus eigener Bibliothek verwenden statt lokal
// zu definieren)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "readline.h"

// Maximum length of player_t.name including terminating null
#define PLAYER_NAME_MAX_LEN 100

typedef struct player_t {
  char name[PLAYER_NAME_MAX_LEN];
  int energy;
} player_t;

void player_init(const char *name, player_t *p) {
  p->energy = 100;
  strncpy(p->name, name, PLAYER_NAME_MAX_LEN);
}

void player_init_ask_user_for_name(player_t *p) {
  char buf[PLAYER_NAME_MAX_LEN];
  readline(buf, PLAYER_NAME_MAX_LEN);

  player_init(buf, p);
  printf("Created player '%s'\n", p->name);
}

int main(void) {
  player_t p;
  player_init_ask_user_for_name(&p);
  printf("Test\n");
  printf("Test\n");
  printf("New player: '%s'\n", p.name);

  return EXIT_SUCCESS;
}
