#include <stdio.h>
#include <stdlib.h>

// Ausbaustufe 2:
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

int main(void) {
  const int line_sz = 1024;
  char line[line_sz];

  read_line(line, line_sz);

  printf("Read: %s\n", line);

  return EXIT_SUCCESS;
}
