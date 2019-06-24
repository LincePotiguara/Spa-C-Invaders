# Compiler flags
CFLAGS=-Wall -pedantic
# Linker flag
LFLAGS=-lncurses
# File objects
OBJS=main.o caracters.o game_loop.o
SOURCES=main.c characters.c game_loop.c sprites.c
EXEC=spac

default: all

spac:
	$(CC) -o $(EXEC) $(SOURCES) $(CFLAGS) $(LFLAGS)

clean:
	rm spac

all:
ifeq (ls | grep $(EXEC), $(EXEC))
	clean $(CC) -o $(EXEC) $(SOURCES) $(CFLAGS) $(LFLAGS)
else
	$(CC) -o $(EXEC) $(SOURCES) $(CFLAGS) $(LFLAGS)
endif

