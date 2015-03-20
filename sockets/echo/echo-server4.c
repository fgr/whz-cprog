#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

// Ausbaustufe 4: Fehlerbehandlung (beliebig viele Verbindungen pro
// Programmlauf, aber nur ein Verbindung zu einem Zeitpunkt)
int main(void) {
  const int server_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (-1 == server_sock) {
    fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  server_addr.sin_port = htons(20000);

  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) ==
      -1) {
    fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  printf("Waiting for connections from clients...\n");
  if (listen(server_sock, 10) == -1) {
    // besser perror verwenden
    fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  while(true) {
    const int client_sock = accept(server_sock, NULL, NULL);
    if (-1 == client_sock) {
      perror("Error opening socket.");
      exit(1);
    }
    printf("Connection established.\n");

    const int buffer_sz = 100;
    char buffer[buffer_sz];  // Puffer fuer empfangene und zu sendende Daten
    int bytes_received = -1; // Anzahl der empfangen Bytes

    // Daten vom Client lesen
    if ((bytes_received = recv(client_sock, buffer, buffer_sz, 0)) == -1) {
      perror("Failed to receive initial data from client");
      exit(EXIT_FAILURE);
    }

    // Daten zum Client senden und weitere Daten vom Client lesen
    while (bytes_received > 0) {
      if (send(client_sock, buffer, bytes_received, 0) != bytes_received) {
        perror("Failed to send data to client");
        exit(EXIT_FAILURE);
      }

      if ((bytes_received = recv(client_sock, buffer, buffer_sz, 0)) == -1) {
        perror("Failed to receive additional data from client");
        exit(EXIT_FAILURE);
      }
    }

    // Keine weiteren Daten vom Client; Verbindung schliessen
    if (close(client_sock) == -1) {
      perror("Warning: Error closing client socket.\n");
    }
    printf("Connection closed.\n");
  }

  if (close(server_sock) == -1) {
    perror("Warning: Error closing server socket.\n");
  }

  return EXIT_SUCCESS;
}
