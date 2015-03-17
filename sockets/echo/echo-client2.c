#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Ausbaustufe 2: Daten zum Server senden und empfangen
// (Achtung: Fehlerbehandlung fehlt!)
int main(void) {
  // Socket erzeugen
  const int client_sock = socket(AF_INET, SOCK_STREAM, 0);

  // Verbindung herstellen
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));
  server_addr.sin_port = htons(20000);
  connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  printf("Connection established; server %s:%i\n",
          inet_ntoa(server_addr.sin_addr), server_addr.sin_port);

  while (true) {
    const int str_max_len = 100;
    char sendstr[str_max_len + 1];
    char recvstr[str_max_len + 1];

    // Strings ausnullen
    memset(sendstr, 0, str_max_len + 1);
    memset(recvstr, 0, str_max_len + 1);

    // Von Standardeingabe lesen
    fgets(sendstr, str_max_len, stdin);

    // Auf TCP-Socket schreiben
    write(client_sock, sendstr, strlen(sendstr) + 1);
    read(client_sock, recvstr, str_max_len);
    printf("Server said: %s\n", recvstr);
  }

  close(client_sock);
  printf("Connection closed.\n");

  return EXIT_SUCCESS;
}
