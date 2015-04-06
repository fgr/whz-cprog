// Player (Ausbaustufe 7: player_t und dessen name-Member jetzt *hintereinander*
// im dynamischen Speicher)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "readline.h"

typedef struct player_t {
  char *name;
  int energy;
} player_t;

player_t *player_new(const char *name) {
  size_t namelen = strlen(name) + 1;

  player_t *p = malloc(sizeof(player_t) + namelen);
  if (p == NULL) {
    perror("Could not allocate heap memory for player_t and player_t.name!");
    exit(EXIT_FAILURE);
  }

  p->energy = 100;

  // Erklaerung fuer unsigned char* siehe http://stackoverflow.com/a/1864977
  // und http://c2.com/cgi/wiki?PointerArithmetic
  // (Zusammenfassung: char-Typ, da garantiert 1 Byte groß; unsigned da nur dann
  // ohne Padding (siehe http://en.wikipedia.org/wiki/Data_structure_alignment
  // und http://stackoverflow.com/a/4306269))
  p->name = (char *)(((unsigned char *)p) + sizeof(player_t));
  strncpy(p->name, name, namelen);

  return p;
}

void player_free(player_t *p) {
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
  p = NULL;
}
