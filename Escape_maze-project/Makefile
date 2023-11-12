# Makefile for the Escape Maze project

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 

all: player

player: player.o maze.o main.o
    $(CC) $(CFLAGS) -o player player.o maze.o main.o -lSDL2 -lncurses

player.o: player.c player.h
    $(CC) $(CFLAGS) -c -o player.o player.c

maze.o: maze.c maze.h
    $(CC) $(CFLAGS) -c -o maze.o maze.c

main.o: main.c player.h maze.h
    $(CC) $(CFLAGS) -c -o main.o main.c

clean:
    rm -f player player.o maze.o main.o
        