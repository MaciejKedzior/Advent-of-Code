#ifndef INTCODE_h
#define INTCODE_H
#define SIZE 1024
//#define NAME 64
#include <stdint.h>
#include <stdbool.h>

typedef struct intcode{
    int32_t     loaded_program_size;
    int32_t     instruction_pointer;
    int32_t     memory[SIZE];
    //char        name[NAME];
    bool        debug_mode;
}IntCode;


void    initialize(const char *path, IntCode *computer, int debug);
void    reset_memory(IntCode *computer, int *original);
void    add(IntCode *computer, int arg1, int arg2, int arg3, int mode[]);
void    mpy(IntCode *computer, int arg1, int arg2, int arg3, int mode[]);
void    input(IntCode *computer, int value, int address);
int     output(IntCode *computer, int address, int mode[]);
void    jmp_true(IntCode *computer, int location, int tested, int jump_to, int mode[]);
void    jmp_false(IntCode *computer, int location, int tested, int jump_to, int mode[]);
void    less_than(IntCode *computer, int arg1, int arg2, int address, int mode[]);
void    equals(IntCode *computer, int arg1, int arg2, int address, int mode[]);
void    param_modes(int array[], int opcode);
int     run(IntCode *computer, int input_values[]);


#endif