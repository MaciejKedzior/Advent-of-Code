#include <stdio.h>
#include <stdlib.h>
#include "game_console.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Write filename!\n");
        exit(EXIT_FAILURE);
    }
    GameConsole console;
    prepareConsole(&console, argv[1]);
    printf("D8P2: %d\n", part2(&console));

    return 0;
}