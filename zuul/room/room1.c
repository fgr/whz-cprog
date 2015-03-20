// Ausbaustufe 1

#include <string.h>

// Maximum length of room_t.name including terminating null
#define ROOM_NAME_MAX_LEN 50

typedef struct room_t {
  char name[ROOM_NAME_MAX_LEN];
} room_t;

room_t room_create(const char *name) {
  struct room_t r;
  strncpy(r.name, name, ROOM_NAME_MAX_LEN);
  return r;
}

#include <stdio.h>

int main() {
  room_t r = room_create("R1");
  printf("%s", r.name);
}
