// Player (Ausbaustufe 5: player_t verwendet dynamischen Speicher (Heap statt
// automatischen Call-Stack-Speicher))
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

player_t *player_new(const char *name) {
  player_t *p = malloc(sizeof(player_t));

  if (p == NULL) {
    perror("Could not allocate heap memory for player_t!");
    exit(EXIT_FAILURE);
  }

  strncpy(p->name, name, PLAYER_NAME_MAX_LEN);
  p->energy = 100;

  return p;
}

player_t *player_new_ask_user_for_name() {
  char buf[PLAYER_NAME_MAX_LEN];
  readline(buf, PLAYER_NAME_MAX_LEN);

  player_t *p = player_new(buf);
  printf("Created player '%s'\n", p->name);
  return p;
}

int main(void) {
	player_t *p = player_new_ask_user_for_name();
	printf("New player '%s'.\n", p->name);
	free(p);
}
