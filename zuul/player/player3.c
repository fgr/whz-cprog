// Player (Ausbaustufe 3: Kopie bei player_t-Erzeugung vermeiden)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

// Maximum length of player_t.name including terminating null
#define PLAYER_NAME_MAX_LEN 100

typedef struct player_t {
  char name[PLAYER_NAME_MAX_LEN];
  int energy;
} player_t;

void player_init(const char *name, player_t *p) {
  (*p).energy = 100;
  strncpy((*p).name, name, PLAYER_NAME_MAX_LEN);
}

void player_init_ask_user_for_name(player_t *p) {
  char buf[PLAYER_NAME_MAX_LEN];
  read_line(buf, PLAYER_NAME_MAX_LEN);

  player_init(buf, p);
  printf("Created player '%s'\n", p->name);
}

void player_init_ask_user_for_name2(player_t *p) {
  read_line(p->name, PLAYER_NAME_MAX_LEN);
  p->energy = 100;
  printf("Created player '%s'\n", p->name);
}

int main(void) {
  player_t p;
  player_init_ask_user_for_name2(&p);
  printf("Test\n");
  printf("Test\n");
  printf("New player: '%s'\n", p.name);

  return EXIT_SUCCESS;
}
