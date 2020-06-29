CC := gcc
CFLAGS := -O3 -Wall -std=c99
LDFLAGS := -s

.PHONY: all clean

all: part1.x part2.x

part1.x: part1.o intcode.o
part1.o: part1.c

part2.x: part2.o intcode.o
part1.o: part2.c

intcode.o: intcode.c


%.x: %.o
	$(CC) $^ -o $@  $(LDFLAGS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])
