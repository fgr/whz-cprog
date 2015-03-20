#include <stdio.h>
#include <stdlib.h>

// Ausbaustufe 1a
// Funktion read_line liest Zeile von Standardeingabe ein, gibt diese aber nur
// auf Standardausgabe aus, aber nicht an Aufrufer zurueck
void read_line(void) {
  const int buf_sz = 1024;
  char buf[buf_sz + 1]; // Null-Terminierung
  int c, i = 0;
  while ((i < buf_sz) &&
         ((c = getc(stdin)) !=
          EOF)) { // Klammer um c = getc ist wichtig, sonst erst !=
    if (c == '\n' || (i == buf_sz - 1)) {
      buf[i] = 0; // Null-Terminierung
      break;
    }
    buf[i] = c;
    ++i;
  }
  printf("input: %s", buf);
}

int main(void) {
  read_line();
  return EXIT_SUCCESS;
}
