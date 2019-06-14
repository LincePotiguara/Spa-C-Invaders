all: spac

spac: main.c
	$(CC) -o spac main.c -Wall -pedantic -lncurses

clean:
	rm spac