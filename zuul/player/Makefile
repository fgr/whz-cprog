CFLAGS=-std=c11 -Wall

PLAYER_SOURCES=$(wildcard player*.c)
PLAYER_PROGRAMS=$(patsubst %.c,%,$(PLAYER_SOURCES))

all: $(PLAYER_PROGRAMS)

player4: player4.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

player5: player5.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf $(PLAYER_PROGRAMS)
