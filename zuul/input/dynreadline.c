#include "dynreadline.h"

#define _GNU_SOURCE // cause stdio.h to include asprintf
#include <stdio.h>
#include <stdbool.h>

char *dynreadline() {
  char *line = NULL;
  static const int bufsz = 100;
  char buf[bufsz];

  bool done = false;
  while (!done) {
    int c, i = 0;
    while ((i < bufsz - 1) &&
           ((c = getc(stdin)) != EOF)) { // buf_sz -1 wegen \0
      if (c == '\n') {
        buf[i] = 0;
        done = true;
        break;
      }
      buf[i] = c;
      ++i;
    }

    buf[i] = 0;

    // buf ans Ende von line anhaengen
    if (line == NULL) { // line ist noch kein String (noch nicht initialisiert)
      asprintf(&line, "%s", buf);
    } else {
      asprintf(&line, "%s%s", line, buf);
    }
  }

  return line;
}

char *dynreadline_prompt(const char *prompt) {
  printf("%s: ", prompt);
  return dynreadline();
}
