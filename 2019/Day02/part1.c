#include <stdio.h>
#include "intcode.h"


int main(int argc, const char* argv[]){
    IntCode     machine;


    load_data(argv[1], machine.memory, &machine.loaded_program_size);
    machine.memory[1] = 12;
    machine.memory[2] = 2;

    printf("Intcode program loaded, memory used: %d units\n", machine.loaded_program_size);

    printf("Opcode\tFirst\tSecond\tOutput\n");
    for (int i=0; i < 20; i+=4) printf("%d\t%d\t%d\t%d\n", machine.memory[i], machine.memory[i+1], machine.memory[i+2], machine.memory[i+3]);
    printf("....\n");
    for (int i=244; i < SIZE; i+=4) printf("%d\t%d\t%d\t%d\n", machine.memory[i], machine.memory[i+1], machine.memory[i+2], machine.memory[i+3]);
    printf("\n");
    
    run(&machine);
    printf("Value at 0-th address position is: %d\n", machine.memory[0]);
    return 0;
}