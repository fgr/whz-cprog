#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// Ausbaustufe 1: Verbindung zum Server aufbauen
// (Achtung: Fehlerbehandlung fehlt!)
int main(void) {
  // Creates an endpoint for communication and returns a descriptor.
  // AF_INET fuer IPv4-Verbindung
  // SOCK_STREAM und 0 fuer TCP (Provides sequenced, reliable, two-way,
  // connection-based byte streams.)
  const int client_sock = socket(AF_INET, SOCK_STREAM, 0);

  // Daten des Server-Kommunikationsendpunktes initialiseren
  struct sockaddr_in server_addr;
  // Alle Felder ausnullen
  memset(&server_addr, 0, sizeof(server_addr));
  // IPv4-Verbindung
  server_addr.sin_family = AF_INET;
  // IP-String zu binaerer IPv4-Adresse
  inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));
  // Server akzeptiert Verbindungen an TCP-Port 20000
  server_addr.sin_port = htons(20000);

  // Verbindung herstellen
  connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  printf("Connection established; server %s:%i\n",
         inet_ntoa(server_addr.sin_addr), server_addr.sin_port);

  // Auf Tastendruck warten
  getchar();

  // Verbindung trennen
  close(client_sock);
  printf("Connection closed.\n");
}
