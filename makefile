# Compiler flags
CFLAGS=-Wall -pedantic
# Linker flag
LFLAGS=-lncurses

all: clean spac

spac:
	$(CC) -o spac sprites.c main.c $(CFLAGS) $(LFLAGS)

clean:
	rm spac