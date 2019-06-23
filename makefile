# Compiler flags
CFLAGS=-Wall -pedantic
# Linker flag
LFLAGS=-lncurses
# File objects

OBJS=main.o
SOURCES=main.c

all: clean spac

spac:
	$(CC) -o spac $(SOURCES) $(CFLAGS) $(LFLAGS)

clean:
	rm spac