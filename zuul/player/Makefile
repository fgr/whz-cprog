CFLAGS=-std=c11 -Wall

PLAYER_SOURCES=$(wildcard player*.c)
PLAYER_PROGRAMS=$(patsubst %.c,%,$(PLAYER_SOURCES))

all: $(PLAYER_PROGRAMS)

player4: player4.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

player5: player5.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

player6: player6.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

player6a: player6a.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

player7: player7.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf $(PLAYER_PROGRAMS)
