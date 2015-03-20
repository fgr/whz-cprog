// Player (Ausbaustufe 2a: player_new_ask_user_for_name verwendet Puffer
// player_t.name statt eigenen, um Name des Spielers von Standardeingabe zu
// lesen. NICHT zu empfehlen, da Vermischung zweier Aufgaben - Name einlesen und
// Spieler erzeugen!)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PLAYER_NAME_MAX_LEN 100 // Maximum length of player_t.name including terminating null

void read_line(char *buf, int buf_sz) {
  int c, i = 0;
  while ((i < buf_sz - 1) && ((c = getc(stdin)) != EOF)) { // buf_sz -1 wegen \0
    if (c == '\n') {
      break;
    }
    buf[i] = c;
    ++i;
  }
  buf[i] = 0; // Null-Terminierung
}

typedef struct player_t {
  char name[PLAYER_NAME_MAX_LEN];
  int energy;
} player_t;

player_t player_new_ask_user_for_name() {
  // char buf[PLAYER_NAME_MAX_LEN]; // Nicht verwendet! 
  player_t p;
  read_line(p.name, PLAYER_NAME_MAX_LEN);
  p.energy = 100;
  printf("Created player '%s'\n", p.name);
  return p;
}

int main(void) {
  struct player_t p = player_new_ask_user_for_name();
  printf("Test\n");
  printf("Test\n");
  printf("New player: '%s'\n", p.name);

  return EXIT_SUCCESS;
}
