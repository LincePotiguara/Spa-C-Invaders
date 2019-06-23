# Compiler flags
CFLAGS=-Wall -pedantic
# Linker flag
LFLAGS=-lncurses
# File objects
OBJS=main.o caracters.o game_loop.o
SOURCES=main.c characters.c game_loop.c sprites.c

spac:
	$(CC) -o spac $(SOURCES) $(CFLAGS) $(LFLAGS)

all: clean spac

clean:
	rm spac