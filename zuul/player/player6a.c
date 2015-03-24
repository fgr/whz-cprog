// Player (Ausbaustufe 6a: Prozedur player_free gibt dynamisch allozierten
// Speicher von player_t.name und player_t frei.)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "readline.h"

typedef struct player_t {
  char *name;
  int energy;
} player_t;

player_t *player_new(const char *name) {
  player_t *p = malloc(sizeof(player_t));

  if (p == NULL) {
    perror("Could not allocate heap memory for player_t!");
    exit(EXIT_FAILURE);
  }

  size_t namelen = strlen(name) + 1;
  p->name = malloc(namelen);

  if (p->name == NULL) {
    perror("Could not allocate heap memory for player_t.name!");
    exit(EXIT_FAILURE);
  }

  strncpy(p->name, name, namelen);
  p->energy = 100;

  return p;
}

void player_free(player_t *p) {
  free(p->name);
  free(p);
  printf("Freed player\n");
}

player_t *player_new_ask_user_for_name() {
  const int bufsz = 100;
  char buf[bufsz];
  readline(buf, bufsz);

  player_t *p = player_new(buf);
  printf("Created player '%s'\n", p->name);
  return p;
}

int main(void) {
  player_t *p = player_new_ask_user_for_name();
  printf("New player '%s'.\n", p->name);
  player_free(p);
}

