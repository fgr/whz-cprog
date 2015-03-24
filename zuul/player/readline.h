// Header-Datei (-> http://de.wikipedia.org/wiki/Header-Datei)

// Include-Guard (-> http://de.wikipedia.org/wiki/Include-Guard)
#ifndef ZUUL_READLINE_H
#define ZUUL_READLINE_H

#include <stddef.h>

void readline(char *buffer, size_t buffer_size);

// size_t statt int fuer Puffergroesse buffer_size
// -> http://en.wikipedia.org/wiki/Size_t
// -> http://www.embedded.com/electronics-blogs/programming-pointers/4026076/Why-size-t-matters

#endif // ZUUL_READLINE_H
