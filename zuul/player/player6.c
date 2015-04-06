// Player (Ausbaustufe 6: name-Member von player_t ist jetzt dynamischer
// String, der nur so viel Speicher verwendet, wie fuer Namen benotigt; bisher
// waren es immer PLAYER_NAME_MAX_LEN Byte)
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
  free(p->name);
  p->name = NULL; // nicht notwendig
  free(p);
  p = NULL;
}
