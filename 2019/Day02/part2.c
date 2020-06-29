#include <stdio.h>
#include <stdlib.h>
#include "intcode.h"
#define VALUE 19690720


int main(int argc, const char* argv[]){
    IntCode     machine;
    
    load_data(argv[1], machine.memory, &machine.loaded_program_size);
    printf("Intcode program loaded, memory used: %d units\n", machine.loaded_program_size);


    int copy[machine.loaded_program_size];
    for (int i=0; i<machine.loaded_program_size; i++) copy[i] = machine.memory[i];


    for (int i=0; i<99; i++){
        for (int j=0; j<99; j++){
            reset_memory(&machine, copy);
            machine.memory[1] = i;  machine.memory[2] = j;
            run(&machine);
            if (machine.memory[0] == VALUE){
                printf("Result: %d\n", 100*i+j);
                exit(EXIT_SUCCESS);
            } 
        }
    }
    

    return 0;
}