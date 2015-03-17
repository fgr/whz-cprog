#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// Ausbaustufe 1a: Verbindungen von Clients annehmen (nur eine Verbindung
// gleichzeitig moeglich) und Verbindungsdaten ausgeben (-> accept)
int main(void) {
  // Creates an endpoint for communication and returns a descriptor.
  // - AF_INET fuer IPv4-Verbindung
  // - SOCK_STREAM und 0 fuer TCP (Provides sequenced, reliable, two-way,
  //   connection-based byte streams.)
  const int server_sock = socket(AF_INET, SOCK_STREAM, 0);

  // Daten des Server-Kommunikationsendpunktes initialiseren
  struct sockaddr_in server_addr;
  // Alle Felder ausnullen
  memset(&server_addr, 0, sizeof(server_addr));
  // IPv4-Verbindung
  server_addr.sin_family = AF_INET;
  // Auf allen Netzwerk-Interfaces auf Verbindungen warten
  server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  // Auf Verbindungen an TCP-Port 20000 warten
  server_addr.sin_port = htons(20000);

  // assigns the address specified by serv_addr to the socket referred to by the
  // file descriptor server_sock
  bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

  printf("Waiting for connections from clients...\n");

  // listen for connections on a socket. (blockierendes Warten)
  // marks the socket referred to by sockfd as a passive socket, that is, as a
  // socket that will be used to accept incoming connection requests using
  // accept.
  // - 10 = maximum length to which the queue of pending connections
  listen(server_sock, 10);

  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  const int client_sock =
      accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);

  printf("Connection established to client %s:%i\n",
         inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

  getchar();
  close(client_sock);
  printf("Connection closed.\n");
}
