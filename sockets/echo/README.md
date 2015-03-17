# Echo-Server und -Client

## Ohne Programmieraufwand:

Mit netcat (nc):

* Server starten: nc -l localhost 20000
* Client zum Server verbinden: nc localhost 20000

## Analyse der TCP-Verbindung mit netstat

* Verbindung zum Server herstellen
* Mit "sudo netstat -anp" aufgebaute Verbindung anzeigen
  * sudo verwenden, um Prozess-ID und -Namen angezeigt zu bekommen (benötigt root-Rechte)
* Mit "sudo netstat -lnptu" alle TCP-Verbindungen im Zustand "listening" anzuzeigen
* 
