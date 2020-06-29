#ifndef INTCODE_h
#define INTCODE_H
#define SIZE 256


typedef struct intcode{
    int loaded_program_size;
    int memory[SIZE];
}IntCode;


void load_data(const char *path, int *integer_array, int *program_size);
void reset_memory(IntCode *computer, int *original);
void add_op(IntCode *computer, int position1, int position2, int final_address);
void mpy_op(IntCode *computer, int position1, int position2, int final_address);
void run(IntCode *computer);


#endif