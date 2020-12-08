#ifndef GAME_CONSOLE_H
#define GAME_CONSOLE_H
#include <stdbool.h>
#define SIZE 610
#define MAX_LENGTH 10


typedef struct instr{
    char operation[3];
    signed int argument;
}Instruction;

typedef struct console{
    Instruction memory[610];
    int accumulator;
    int ptr;
    bool visited[610];
}GameConsole;


void prepareConsole(GameConsole* console ,char* filename);
void runProgram(GameConsole* console);

void printParameters(GameConsole* console);

void copyStructure(GameConsole* dest, GameConsole* src);
void findJMPsandNOPs(Instruction memory[], bool indices[]);
bool quitDueInfiniteLoop(GameConsole* console);
int part2(GameConsole* console);
#endif