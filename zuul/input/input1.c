// Thema 1: Dynamisches readline (verwendet asprintf)
// Thema 2: Parsen von Strings mithilfe von strtok

#define _GNU_SOURCE // cause stdio.h to include asprintf
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

char *readline_with_prompt(const char *prompt) {
  printf("%s: ", prompt);
  return readline();
}

int main(void) {
  char *line = readline_with_prompt("Enter string to parse");
  printf("String entered: '%s'\n", line);

  int i = 0;
  char *separators = " \t";
  char *token = strtok(line, separators);
  while (token != 0) {
    printf("%2d '%s'\n", i++, token);

    token = strtok(NULL, separators);
  }

  free(line);
}
