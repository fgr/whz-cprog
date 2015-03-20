CFLAGS=-std=c11 -Wall

PROG_SOURCES=$(wildcard room*.c)
PROGS=$(patsubst %.c,%,$(PROG_SOURCES))

all: $(PROGS)

clean:
	rm -rf *.o
	rm -rf $(PROGS)
