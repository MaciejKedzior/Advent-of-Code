CC := gcc
CFLAGS := -Wall -std=c99 

.PHONY: all clean

all: part1.x part2.x


part1.x: part1.o game_console.o
part1.o: part1.c 

part2.x: part2.o game_console.o
part2.o: part2.c 

game_console.o: game_console.c game_console.h


%.x: %.o
	$(CC) $^ -o $@  

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])
