// Thema 1: Vergleich von Strings mit mystrcmp.
//    HINWEIS: C-Standard beinhaltet strcmp bereits! Wir implementieren es hier
//    wegen Lerneffekt.
// Thema 2: Enumerations (Aufzaehlungsdatentypen)

#define _GNU_SOURCE // cause stdio.h to include asprintf
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Forward declaration der Prozedur mystrcmp
int mystrcmp(const char *s1, const char *s2);

enum command_type {
  CMD_GO,
  CMD_LOOK,
  CMD_UNKNOWN
};

enum command_type get_command_type(const char *cmd) {
  if (mystrcmp("go", cmd) == 0) {
    return CMD_GO;
  } else if (mystrcmp("look", cmd) == 0) {
    return CMD_LOOK;
  } else {
    return CMD_UNKNOWN;
  }
}

int mystrcmp(const char *s1, const char *s2) {
  int i = 0;
  while ((s1[i] != 0) && (s1[i] == s2[i])) {
    ++i;
  }
  return s1[i] - s2[i];
}

int mystrcmp2(const char *s1, const char *s2) {
  while ((*s1 != 0) && (*s1 == *s2)) {
    ++s1;
    ++s2;
  }
  return *s1 - *s2;
}

typedef struct command_info_t {
  enum command_type cmd_type;
  char *arg;
} command_info_t;

command_info_t parse_input(const char *input) {
  char *input2 =
      strdup(input); // erzeugt duplizierten String auf Heap (malloc())
  char *separators = " \t";
  command_info_t result;

  // parse command
  char *token = strtok(input2, separators);
  if (token == NULL) {
    result.cmd_type = CMD_UNKNOWN;
    result.arg = NULL;
    goto exit;
  }
  result.cmd_type = get_command_type(token);

  // parse argument
  token = strtok(NULL, separators);
  if (token == NULL) {
    result.arg = NULL;
    goto exit;
  }
  result.arg = strdup(token);

exit:
  free(input2);
  return result;
}

int main(void) {
  char *line = dynreadline_prompt("Enter command");
  printf("Command: '%s'\n", line);

  command_info_t cmdinfo = parse_input(line);

  printf("cmdinfo.cmd_type: %d | .arg: '%s'\n", cmdinfo.cmd_type, cmdinfo.arg);

  free(line);
  free(cmdinfo.arg);
}
