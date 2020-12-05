CC := gcc
CFLAGS := -Wall -std=c99

.PHONY: all clean

all: part1.x part2.x


part1.x: part1.o utils.o
part1.o: part1.c 

part2.x: part2.o utils.o
part2.o: part2.c 

utils.o: utils.c utils.h


%.x: %.o
	$(CC) $^ -o $@  

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])
