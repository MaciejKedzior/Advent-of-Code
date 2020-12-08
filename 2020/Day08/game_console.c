#include "game_console.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void prepareConsole(GameConsole* console ,char* filename){
    memset(console->visited, 0, SIZE);

    char buffer[MAX_LENGTH];
    FILE* fptr = fopen(filename, "r");
    int i=0;

    if (fptr == NULL){
        perror("Error opening file!");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, MAX_LENGTH, fptr)){
        //printf("i=%d, buffer = %s", i, buffer);
        strcpy(console->memory[i].operation, strtok(buffer," "));
        console->memory[i].argument = atoi(strtok(NULL, " "));
        //printf("In console: %s\t%d\n", console->memory[i].operation, console->memory[i].argument);
        i++;
    }
}


void runProgram(GameConsole* console){
    int* helper = &console->ptr;

    while (!console->visited[*helper]){
        if (!strcmp(console->memory[*helper].operation, "acc")){
            console->accumulator += console->memory[*helper].argument;
            console->visited[*helper] = true;
            (*helper)++;
        }
        else if (!strcmp(console->memory[*helper].operation, "jmp")){
            console->visited[*helper] = true;
            (*helper)+=console->memory[*helper].argument;
        }
        else if (!strcmp(console->memory[*helper].operation, "nop")){
            console->visited[*helper] = true;
            (*helper)++;
        }
    }
}

bool quitDueInfiniteLoop(GameConsole* console){
    int* helper = &console->ptr;
    bool infLoop = console->visited[*helper], afterLast = *helper >= SIZE;

    while (!(infLoop || afterLast)){
        if (!strcmp(console->memory[*helper].operation, "acc")){
            console->accumulator += console->memory[*helper].argument;
            console->visited[*helper] = true;
            (*helper)++;
        }
        else if (!strcmp(console->memory[*helper].operation, "jmp")){
            console->visited[*helper] = true;
            (*helper)+=console->memory[*helper].argument;
        }
        else if (!strcmp(console->memory[*helper].operation, "nop")){
            console->visited[*helper] = true;
            (*helper)++;
        }

        infLoop = console->visited[*helper];
        afterLast = *helper >= SIZE;  
    }
    if (infLoop) return true;
        return false;
}


void findJMPsandNOPs(Instruction memory[], bool indices[]){
    for (int i=0; i < SIZE; i++){
        if (!strcmp(memory[i].operation, "jmp") || !strcmp(memory[i].operation, "nop")){
            indices[i] = true;
        }
    }
}

void copyStructure(GameConsole* dest, GameConsole* src){
    for (int i=0; i < SIZE; i++){
        strcpy(dest->memory[i].operation, src->memory[i].operation);
        dest->memory[i].argument = src->memory[i].argument;
    }

    dest->accumulator = src->accumulator;
    dest->ptr = src->ptr;
    for (int i=0; i < SIZE; i++){
        dest->visited[i]= src->visited[i];
    }
}


int part2(GameConsole* console){
    bool indices[SIZE]; memset(indices, false, SIZE*(sizeof(bool)));
    findJMPsandNOPs(console->memory, indices);

    int counter=0;
    for (int i=0; i < SIZE; i++){
        if (!indices[i]) continue;

        GameConsole copy;
        copyStructure(&copy, console);        

        if (!strcmp(copy.memory[i].operation, "jmp"))
            strcpy(copy.memory[i].operation, "nop");
        else
            strcpy(copy.memory[i].operation, "jmp");

        if (!quitDueInfiniteLoop(&copy))
            return copy.accumulator;
        counter++;
    }

    exit(EXIT_FAILURE);
}

void printParameters(GameConsole* console){
    printf("Accumulator = %d\n", console->accumulator);
    printf("Pointer = %d\n", console->ptr);
}