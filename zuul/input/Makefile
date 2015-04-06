CFLAGS=-std=c11 -Wall

SOURCES=$(wildcard *.c)
PROGRAMS=$(patsubst %.c,%,$(SOURCES))

all: $(PROGRAMS)

input2: input2.o dynreadline.o
	$(CC) $(CFLAGS) -o $@ $^
