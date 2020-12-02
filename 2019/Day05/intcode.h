#ifndef INTCODE_h
#define INTCODE_H
#define SIZE 1024


typedef struct intcode{
    int loaded_program_size;
    int instruction_pointer;
    int memory[SIZE];
}IntCode;


void    load_data(const char *path, IntCode *computer);
void    reset_memory(IntCode *computer, int *original);
void    add(IntCode *computer, int arg1, int arg2, int arg3, int mode[]);
void    mpy(IntCode *computer, int arg1, int arg2, int arg3, int mode[]);
void    input(IntCode *computer, int value, int address);
void    output(IntCode *computer, int address, int mode[]);
void    jmp_true(IntCode *computer, int location, int tested, int jump_to, int mode[]);
void    jmp_false(IntCode *computer, int location, int tested, int jump_to, int mode[]);
void    less_than(IntCode *computer, int arg1, int arg2, int address, int mode[]);
void    equals(IntCode *computer, int arg1, int arg2, int address, int mode[]);
void    param_modes(int array[], int opcode);
void    run(IntCode *computer, int input_value);


#endif