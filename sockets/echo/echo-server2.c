#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// Ausbaustufe 2: Daten vom Client empfangen und zuruecksenden (Nur eine
// Verbindung pro Programmlauf)
int main(void) {
  const int server_sock = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  server_addr.sin_port = htons(20000);

  bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

  printf("Waiting for connections from clients...\n");
  listen(server_sock, 10);

  const int client_sock = accept(server_sock, NULL, NULL);
  printf("Connection established.\n");

  const int buffer_sz = 100;
  char buffer[buffer_sz];

  // Daten vom Client lesen
  int bytes_received = recv(client_sock, buffer, buffer_sz, 0);

  // Daten zum Client senden und weitere Daten vom Client lesen
  while (bytes_received > 0) {
    send(client_sock, buffer, bytes_received, 0);
    bytes_received = recv(client_sock, buffer, buffer_sz, 0);
  }

  // Keine weiteren Daten vom Client; Verbindung schliessen
  close(client_sock);
  close(server_sock);
  printf("Connection closed.\n");
}
