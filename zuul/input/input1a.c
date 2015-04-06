// readline_with_prompt verwendet Zeiger auf Eingabefunktion (Funktionszeiger)

#define _GNU_SOURCE // cause stdio.h to include asprintf
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *readline_with_prompt(const char *prompt,
                           char *(*readline_func)(const char *)) {
  printf("%s: ", prompt);
  return readline_func(prompt);
}

char *readline() {
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

int main(void) {
  char *line = readline_with_prompt("Enter a string", readline);
  printf("String entered: '%s'\n", line);
  free(line);
}
