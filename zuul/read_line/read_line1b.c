#include <stdio.h>
#include <stdlib.h>

// Ausbaustufe 1b
// Idee: C-String (Array) aus read_line zurueckgeben.
// Problem: C erlaubt Rueckgabe von Array nicht (-> http://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm)
/*
char[1025] read_line(void) {
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
*/

int main(void) {
  // char line[1025] = read_line(); // Geht nicht!
  
  return EXIT_SUCCESS;
}
