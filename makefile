# Compiler flags
CFLAGS=-Wall -pedantic
# Linker flag
LFLAGS=-lncurses

all: clean spac

spac:
	$(CC) -o spac main.c $(CFLAGS) $(LFLAGS)

clean:
	rm spac