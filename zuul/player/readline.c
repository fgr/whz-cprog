#include "readline.h"

#include <stdio.h>

void readline(char *buf, size_t buf_sz) {
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
