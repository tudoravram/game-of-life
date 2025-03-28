CC = gcc
CFLAGS = -Wall -g

all: game_of_life

game_of_life: game_of_life.o
	$(CC) $(CFLAGS) -o game_of_life game_of_life.o

game_of_life.o: game_of_life.c
	$(CC) $(CFLAGS) -c game_of_life.c

clean:
	rm -f *.o game_of_life game_of_life.exe
